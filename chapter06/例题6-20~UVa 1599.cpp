#include<bits/stdc++.h>
using namespace std;
struct Edge{//边的类
    int v1,v2,color;
    Edge(int vv1,int vv2,int c):v1(vv1),v2(vv2),color(c) {}
};
const int MAX=100000;
int n,m,dis[MAX+5];
bool visit[MAX+5];
vector<Edge>edges;//存储每条边
vector<int>graph[MAX+5];//图
void revBFS(){//以顶点n为起点，计算出结点n到达每一个结点的最短距离
    memset(visit,0,sizeof(visit));
    queue<int>q;
    q.push(n);
    visit[n]=true;
    dis[n]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i:graph[t]){
            int v=(edges[i].v1==t)?edges[i].v2:edges[i].v1;//到达的顶点编号
            if(!visit[v]){
                visit[v]=true;
                q.push(v);
                dis[v]=dis[t]+1;
            }
        }
    }
}
void BFS(){//以结点1为起点，再使用一次BFS算法找出最优路径
    printf("%d\n",dis[1]);//输出最短路径长度
    memset(visit,0,sizeof(visit));
    visit[1]=true;
    vector<int>currentLevel;//当前最短距离下包含的顶点
    currentLevel.push_back(1);
    for(int j=0;j<dis[1];++j){
        int minColor=INT_MAX;//最小的颜色号
        for(int i:currentLevel){//遍历前当最短距离下包含的所有顶点
            for(int j:graph[i]){//遍历该顶点的所有边
                int v=(edges[j].v1==i)?edges[j].v2:edges[j].v1;
                if(dis[v]+1==dis[i])//到达的顶点是最短距离正好少1的点
                    minColor=min(minColor,edges[j].color);//更新minColor
            }
        }
        vector<int>nextLevel;//存储当前最短距离正好少1包含的所有顶点
        for(int i:currentLevel){
            for(int j:graph[i]){
                int v=(edges[j].v1==i)?edges[j].v2:edges[j].v1;
                if(!visit[v]&&dis[v]+1==dis[i]&&minColor==edges[j].color){
                    nextLevel.push_back(v);
                    visit[v]=true;
                }
            }
        }
        currentLevel=nextLevel;//转向处理最短距离正好少1包含的所有顶点
        printf("%d%s",minColor,j==dis[1]-1?"\n":" ");//输出颜色编号
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        fill(graph+1,graph+n+1,vector<int>());
        edges.clear();
        int a,b,c;
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            graph[a].push_back(edges.size());
            graph[b].push_back(edges.size());
            edges.push_back(Edge(a,b,c));
        }
        revBFS();
        BFS();
    }
    return 0;
}
