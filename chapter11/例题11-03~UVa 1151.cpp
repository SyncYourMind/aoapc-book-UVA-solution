#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int v1,v2,cost;
    Edge(int vv1,int vv2,int c):v1(vv1),v2(vv2),cost(c) {}
    bool operator <(const Edge&e)const{
        return this->cost>e.cost;
    }
};
priority_queue<Edge>allEdges;//存储图中的所有边
vector<Edge>treeEdges;//存储最小生成树的所有边
vector<pair<int,vector<int>>>subnetworks;//存储所有套餐
vector<int>sub;//存储购买的套餐编号，用于进行枚举
int father[1005],t,n,q,m,a,b,c;//并查集
int findFather(int x){//寻找根结点并进行路径压缩
    if(x==father[x])
        return x;
    int t=findFather(father[x]);
    father[x]=t;
    return t;
}
void unionSets(Edge e,int&cost,int flag){//合并边两端的结点为同一集合。
    int ua=findFather(e.v1),ub=findFather(e.v2);
    if(ua!=ub){
        cost+=e.cost;//将边的权值加到cost上
        father[ua]=ub;//合并两个集合
        if(flag==0)//flag==0表示求解最小生成树
            treeEdges.push_back(e);
    }
}
void DFS(int i,int&ans){//枚举购买的套餐
    if(i==subnetworks.size()){//套餐枚举完成
        int allCost=0;//存储购买当前套餐后的总费用
        iota(father,father+n+1,0);//初始化并查集
        for(auto&i:sub){//遍历购买的套餐编号
            allCost+=subnetworks[i].first;//加上当前套餐的费用
            vector<int>&t=subnetworks[i].second;//当前套餐包含的结点
            for(int j=0;j<t.size();++j)//将套餐内的结点合并到一个集合
                for(int k=j+1;k<t.size();++k)
                    unionSets(Edge(t[j],t[k],0),allCost,1);
        }
        for(Edge&e:treeEdges)//遍历最小生成树中的边
            unionSets(e,allCost,1);//合并边两端的结点
        ans=min(ans,allCost);//更新ans
        return;
    }
    sub.push_back(i);//购买该套餐
    DFS(i+1,ans);
    sub.pop_back();//不购买该套餐
    DFS(i+1,ans);
}
int main(){
    scanf("%d",&t);
    for(int ii=0;ii<t;++ii){
        printf("%s",ii>0?"\n":"");
        treeEdges.clear();
        subnetworks.clear();
        vector<pair<int,int>>cities={{0,0}};//存储结点的坐标
        scanf("%d%d",&n,&q);
        while(q--){
            scanf("%d%d",&m,&c);
            subnetworks.push_back({c,{}});
            while(m--){
                scanf("%d",&a);
                subnetworks.back().second.push_back(a);
            }
        }
        for(int i=1;i<=n;++i){
            scanf("%d%d",&a,&b);
            for(int j=1;j<cities.size();++j)//求所有的边
                allEdges.push(Edge(j,i,(a-cities[j].first)*(a-cities[j].first)+(b-cities[j].second)*(b-cities[j].second)));
            cities.push_back({a,b});
        }
        int ans=0;
        iota(father,father+n+1,0);//初始化并查集
        while(!allEdges.empty()){//求解最小生成树
            Edge e=allEdges.top();
            allEdges.pop();
            unionSets(e,ans,0);
        }
        DFS(0,ans);
        printf("%d\n",ans);
    }
    return 0;
}
