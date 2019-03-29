#include<bits/stdc++.h>
using namespace std;
struct Edge{//边的类
    int v1,v2,weight;
    Edge(int vv1,int vv2,int w):v1(vv1),v2(vv2),weight(w) {}
};
int n,m,father[105];//n、m、并查集
vector<Edge>edges;//存储所有边
int findFather(int x){//查找父结点并进行路径压缩
    if(x==father[x])
        return x;
    int t=findFather(father[x]);
    father[x]=t;
    return t;
}
void unionSets(int a,int b){//合并两个集合
    int ua=findFather(a),ub=findFather(b);
    if(ua!=ub)
        father[ua]=ub;
}
bool countRoots(){//确认并查集内是否只有一个集合
    int num=0;
    for(int i=1;i<=n;++i)
        if(father[i]==i)
            ++num;
    return num==1;
}
int main(){
    while(~scanf("%d%d",&n,&m)&&n!=0){
        edges.clear();
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            edges.push_back(Edge(a,b,c));
        }
        sort(edges.begin(),edges.end(),[](const Edge&e1,const Edge&e2){//排序
            return e1.weight<e2.weight;
        });
        int ans=INT_MAX;//最终结果
        for(int i=0;i<edges.size();++i){//从小到大枚举i
            iota(father,father+n+1,0);//初始化并查集
            for(int j=i;j<edges.size()&&j<i+n-2;++j)//将i~i+n-3这n-2条边两端的点合并成一个集合
                unionSets(edges[j].v1,edges[j].v2);
            for(int j=i+n-2;j<edges.size();++j){//从小到大枚举j
                unionSets(edges[j].v1,edges[j].v2);//将第j条边两端的点合并成一个集合
                if(countRoots()){//并查集内只有一个集合，表示所有点已连通
                    ans=min(ans,edges[j].weight-edges[i].weight);//更新ans
                    break;
                }
            }
        }
        if(ans==INT_MAX)
            puts("-1");
        else
            printf("%d\n",ans);
    }
    return 0;
}
