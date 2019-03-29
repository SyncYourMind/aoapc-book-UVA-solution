#include<bits/stdc++.h>
using namespace std;
const int MAX=30;
unordered_map<string,int>trans;
vector<string>people;
vector<int>graph[MAX];
int n,m,Index[MAX],lowLink[MAX],sccno[MAX],dfsNo,scc_cnt;
stack<int>s;
void init(){//初始化所有全局变量
    trans.clear();
    people.clear();
    fill(graph,graph+n,vector<int>());
    memset(Index,0,sizeof(Index));
    memset(lowLink,0,sizeof(lowLink));
    memset(sccno,0,sizeof(sccno));
    dfsNo=scc_cnt=0;
}
int ID(const string&s){//获取一个任命对应的整数
    if(trans.find(s)==trans.end()){
        trans[s]=people.size();
        people.push_back(s);
    }
    return trans[s];
}
void DFS(int v){//求解强连通分量
    Index[v]=lowLink[v]=++dfsNo;
    s.push(v);
    for(int i:graph[v]){
        if(Index[i]==0){
            DFS(i);
            lowLink[v]=min(lowLink[v],lowLink[i]);
        }else if(sccno[i]==0)
            lowLink[v]=min(lowLink[v],Index[i]);
    }
    if(lowLink[v]==Index[v]){//是一个强连通分支的根结点
        ++scc_cnt;
        int t;
        do{
            t=s.top();
            s.pop();
            printf("%s%s",people[t].c_str(),t==v?"\n":", ");//输出人名
            sccno[t]=scc_cnt;
        }while(t!=v);
    }
}
int main(){
    for(int ii=1;~scanf("%d%d",&n,&m)&&n!=0;++ii){
        printf("%s",ii>1?"\n":"");
        init();
        string name1,name2;
        while(m--){
            cin>>name1>>name2;
            int id1=ID(name1),id2=ID(name2);
            graph[id1].push_back(id2);
        }
        printf("Calling circles for data set %d:\n",ii);
        for(int i=0;i<n;++i)
            if(Index[i]==0)
                DFS(i);
    }
    return 0;
}
