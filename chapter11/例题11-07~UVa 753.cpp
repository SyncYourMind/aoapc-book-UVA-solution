#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int from,to,cap,flow;
    Edge(int f,int t,int c,int fl):from(f),to(t),cap(c),flow(fl){}
};
vector<Edge>edges;
vector<vector<int>>graph(405);
const int INF=0x3fffffff;//无穷大
int t,n,m,k;
int getID(const string&s,unordered_map<string,int>&trans,array<unordered_map<int,int>,3>&num,int flag){
    if(trans.find(s)==trans.end())
        trans.insert({s,trans.size()+1});
    ++num[flag][trans[s]];//递增属于该类型的插座或插头个数
    return trans[s];//返回该类型的结点编号
}
void insertEdge(int id1,int id2,int cap){//插入边
    graph[id1].push_back(edges.size());
    edges.push_back(Edge(id1,id2,cap,0));
    graph[id2].push_back(edges.size());
    edges.push_back(Edge(id2,id1,0,0));
}
int MaxFlow(int s,int t){//最大流算法,s为源点,t为汇点
    int a[405]={0},p[405]={0},flow=0;//a数组表示源点到结点a[i]的残量,p数组表示最短路树上到达结点p[i]的边在edges数组中的序号,最大流量
    while(true){//广度优先遍历查找从源点到达汇点的增广路
        memset(a,0,sizeof(a));//将源点到达每个结点的残量初始化为0
        queue<int>q;
        q.push(s);
        a[s]=INT_MAX;//起点的残量置为无穷大
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i:graph[x]){//遍历以x为起点的边
                Edge&e=edges[i];
                if(a[e.to]==0&&e.cap>e.flow){//当前边的终点的残量为0且容量大于流量
                    p[e.to]=i;//更新到达该终点的边的编号
                    a[e.to]=min(a[x],e.cap-e.flow);//更新源点到该终点的残量
                    q.push(e.to);//压入队列
                }
            }
            if(a[t]!=0)//终点的残量不为零，跳出循环
                break;
        }
        if(a[t]==0)//终点的残量为零，表示不存在增广路了，跳出外层死循环
            break;
        for(int u=t;u!=s;u=edges[p[u]].from){//从汇点向前遍历增广路经，更新每条增广路的流量
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
        }
        flow+=a[t];//增加最大流量
    }
    return flow;
}
int main(){
    scanf("%d",&t);
    for(int ii=0;ii<t;++ii){
        printf("%s",ii>0?"\n":"");
        edges.clear();
        fill(graph.begin(),graph.end(),vector<int>());
        scanf("%d",&n);
        string word,word2;
        unordered_map<string,int>trans;
        array<unordered_map<int,int>,3>num;//存储插座、插头、转换器中出现的每个类型的设备个数
        for(int i=0;i<n;++i){
            cin>>word;
            getID(word,trans,num,0);
        }
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            cin>>word2>>word;
            getID(word,trans,num,1);
        }
        scanf("%d",&k);
        for(int i=0;i<k;++i){
            cin>>word>>word2;
            int id1=getID(word,trans,num,2),id2=getID(word2,trans,num,2);
            insertEdge(id1,id2,INF);
        }
        for(auto&i:num[1])//从源点到所有插头类型连一条边
            insertEdge(0,i.first,i.second);
        for(auto&i:num[0])//从所有插座类型往汇点连一条边
            insertEdge(i.first,400,i.second);
        printf("%d\n",m-MaxFlow(0,400));
    }
    return 0;
}
