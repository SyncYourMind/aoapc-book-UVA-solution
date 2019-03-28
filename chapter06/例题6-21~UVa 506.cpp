#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>trans;//将组件名转换成整数
vector<string>words;//存储所有组件名
vector<vector<int>>graph;//存储所有组件之间的依赖关系
vector<int>status,depend,order;//组件的安装属性、组件被多少个显式安装的组件所依赖、组件的安装顺序
int ID(const string&s){//将一个组件名转换成整数
    if(trans.find(s)==trans.end()){//该组件名还没有出现过
        trans.insert({s,words.size()});
        words.push_back(s);
        graph.push_back({});
        depend.push_back(0);
        status.push_back(0);
    }
    return trans[s];//返回组件在words中的下标
}
void Install(int v,bool source){//安装组件,source表示该组件是否是当前INSTALL指令所要安装的组件
    for(int i:graph[v])//递归安装所有依赖的组件
        Install(i,false);
    if(status[v]==0){//组件未被安装
        status[v]=source?1:2;//更新组件的安装属性
        order.push_back(v);//在order末尾插入该组件
        printf("   Installing %s\n",words[v].c_str());
    }
    if(!source)//当前组件是INSTALL指令所要安装的组件的依赖组件
        ++depend[v];//递增该组件被依赖的显示安装的组件个数
}
void Remove(int v,bool source){//安装组件,source表示该组件是否是当前REMOVE指令所要删除的组件
    depend[v]=max(0,depend[v]-1);//递减该组件被依赖的显示安装的组件个数
    if(depend[v]==0&&(source||status[v]==2)){//该组件可被删除
        status[v]=0;//更新组件的安装属性
        order.erase(find(order.begin(),order.end(),v));//在order中删除该组件
        printf("   Removing %s\n",words[v].c_str());
    }
    for(int i:graph[v])//递归删除所有依赖的组件
        Remove(i,false);
}
int main(){
    string line="",word1,word2,command;
    while(getline(cin,line)&&line!="END"){
        stringstream str;
        str<<line;//将一行字符串放入str中按空格键分割
        str>>command;
        puts(line.c_str());//输出整行命令
        if(command=="LIST"){
            for(int i:order)//打印所有已安装的组件
                printf("   %s\n",words[i].c_str());
        }else{
            str>>word1;
            int a=ID(word1);//获取命令后的第一个组件名所对应的整数
            if(command=="DEPEND"){
                while(str>>word2){//建立依赖关系
                    int b=ID(word2);
                    graph[a].push_back(b);
                }
            }else if(command=="INSTALL"){
                if(status[a]==0){//组件还未安装
                    Install(a,true);//进行安装
                }else//组件已被安装过
                    printf("   %s is already installed.\n",words[a].c_str());
            }else if(command=="REMOVE"){
                if(status[a]==0){//组件未被安装，无法删除
                    printf("   %s is not installed.\n",words[a].c_str());
                }else if(depend[a]==0){//组件没有被依赖的显示安装的组件
                    Remove(a,true);//删除该组件
                }else//组件有被依赖的显示安装的组件
                    printf("   %s is still needed.\n",words[a].c_str());
            }
        }
    }
    puts("END");
    return 0;
}
