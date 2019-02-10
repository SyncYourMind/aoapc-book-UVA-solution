#include<bits/stdc++.h>
using namespace std;
unordered_map<char,string>toBinary={//16进制转2进制
    {'0',"0000"}, {'1',"0001"}, {'2',"0010"}, {'3',"0011"},
    {'4',"0100"}, {'5',"0101"}, {'6',"0110"}, {'7',"0111"},
    {'8',"1000"}, {'9',"1001"}, {'a',"1010"}, {'b',"1011"},
    {'c',"1100"}, {'d',"1101"}, {'e',"1110"}, {'f',"1111"}
};
unordered_map<int,char>toAns={{1,'A'},{3,'J'},{5,'D'},{4,'S'},{0,'W'},{2,'K'}};//白洞个数对应的字符
int H,W,direction[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
vector<string>graph;//存储整个图
void DFS(int i,int j,char c,int&ans){//从graph[i][j]位置开始深度优先搜索,c表示当前搜索的是0还是1字符,ans表示白洞个数
    graph[i][j]=(char)(c+2);//0字符变成2,1字符变成3
    for(int k=0;k<4;++k){//遍历4个周围的字符
        int ii=i+direction[k][0],jj=j+direction[k][1];
        if(ii>=0&&ii<graph.size()&&jj>=0&&jj<graph[i].size()){//如果下一个位置没有越界
            if(c=='1'&&graph[ii][jj]=='0'){//当前位置是1字符，且下一个位置是0字符
                ++ans;//递增白洞个数
                DFS(ii,jj,'0',ans);//从下一个位置开始深搜0字符
            }
            if(graph[ii][jj]==c)//下一个位置与当前位置字符相同
                DFS(ii,jj,c,ans);//继续深搜
        }
    }
}
int main(){
    for(int ii=1;~scanf("%d%d%*c",&H,&W)&&H!=0;++ii){
        graph.resize(H+2);
        graph.front()=string(W*4+2,'0');//加一层白边
        for(int i=1;i<=H;++i){//读取输入
            graph[i]="0";//加一层白边
            string s;
            getline(cin,s);
            for(char c:s)
                graph[i]+=toBinary[c];
            graph[i]+="0";//加一层白边
        }
        graph.back()=string(W*4+2,'0');//加一层白边
        int ans=0;
        string result="";//最终结果
        DFS(0,0,'0',ans);
        for(int i=0;i<graph.size();++i)
            for(int j=0;j<graph[i].size();++j){
                if(graph[i][j]=='1'){
                    ans=0;
                    DFS(i,j,'1',ans);
                    result+=toAns[ans];
                }
            }
        sort(result.begin(),result.end());//按字典序排序
        printf("Case %d: %s\n",ii,result.c_str());//输出
    }
    return 0;
}
