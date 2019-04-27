#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int from,to,cap,flow;
    Edge(int f,int t,int c,int fl):from(f),to(t),cap(c),flow(fl){}
};
const int MAXV=55;
vector<Edge>edges;
vector<vector<int>>graph(MAXV);
int R,C,T,matrix[25][25];
void insertEdge(int from,int to,int cap){
    graph[from].push_back(edges.size());
    edges.push_back(Edge(from,to,cap,0));
    graph[to].push_back(edges.size());
    edges.push_back(Edge(to,from,0,0));
}
void MaxFlow(int s,int t){//最大流算法,s为源点,t为汇点
    int a[MAXV]={0},p[MAXV]={0};//a数组表示源点到结点a[i]的残量,p数组表示最短路树上到达结点p[i]的边在edges数组中的序号
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
    }
}
int main(){
    scanf("%d",&T);
    for(int ii=1;ii<=T;++ii){
        printf("Matrix %d\n",ii);
        edges.clear();
        fill(graph.begin(),graph.end(),vector<int>());
        scanf("%d%d",&R,&C);
        int a=0,b=0;
        for(int i=1;i<=R;++i){
            scanf("%d",&a);
            insertEdge(0,i,a-b-C);
            for(int j=1;j<=C;++j){
                matrix[i][j]=edges.size();
                insertEdge(i,j+R,19);
            }
            b=a;
        }
        a=b=0;
        for(int i=1;i<=C;++i){
            scanf("%d",&a);
            insertEdge(i+R,R+C+1,a-b-R);
            b=a;
        }
        MaxFlow(0,R+C+1);
        for(int i=1;i<=R;++i){
            for(int j=1;j<=C;++j)
                printf("%d ",edges[matrix[i][j]].flow+1);
            puts("");
        }
        puts("");
    }
    return 0;
}
