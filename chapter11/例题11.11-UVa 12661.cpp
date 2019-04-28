#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int from,to,cost,open,close;
    Edge(int f,int t,int o,int clo,int c):from(f),to(t),open(o),close(clo),cost(c){}
};
const int MAXV=305;
vector<Edge>edges;
vector<int>graph[MAXV];
int n,m,s,t,dis[MAXV];
int arriveNext(int arrive,const Edge&e){//计算从到达道路e起点的时间arrive到达道路e终点时间
    int temp=arrive%(e.open+e.close);
    if(temp+e.cost<=e.open)
        return arrive+e.cost;
    return arrive+e.open+e.close-temp+e.cost;
}
void Dijkstra(){
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>>pq;//pii的first成员存储dis，second成员存储结点编号
    fill(dis,dis+MAXV,INT_MAX);
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        pii p=pq.top();
        pq.pop();
        if(dis[p.second]!=p.first)
            continue;
        for(int i:graph[p.second]){
            Edge&e=edges[i];
            int arrive=arriveNext(dis[p.second],e);//到达道路e终点的时间
            if(dis[e.to]>arrive){
                dis[e.to]=arrive;
                pq.push({dis[e.to],e.to});
            }
        }
    }
}
int main(){
    for(int ii=1;~scanf("%d%d%d%d",&n,&m,&s,&t);++ii){
        edges.clear();
        fill(graph,graph+n+1,vector<int>());
        while(m--){
            int u,v,a,b,t;
            scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
            if(t>a)//如果通过该路的用时比该路的开放时间还要长，直接忽略该路
                continue;
            graph[u].push_back(edges.size());
            edges.push_back(Edge(u,v,a,b,t));
        }
        Dijkstra();
        printf("Case %d: %d\n",ii,dis[t]);
    }
    return 0;
}
