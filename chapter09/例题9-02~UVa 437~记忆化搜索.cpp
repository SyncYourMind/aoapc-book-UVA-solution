#include<bits/stdc++.h>
using namespace std;
struct Block{
    int x,y,z;//长宽高
    Block(int xx,int yy,int zz):x(xx),y(yy),z(zz) {}
};
vector<Block>blocks;//存储所有可能摆放的立方体
vector<vector<int>>DAG;//DAG图
int n,dp[200];
int DP(int i){
    if(dp[i]!=0)//该结点已计算过，直接返回值
        return dp[i];
    if(DAG[i].empty())//叶结点
        return dp[i]=blocks[i].z;//返回高
    for(int j:DAG[i])//遍历能到达的结点
        dp[i]=max(dp[i],blocks[i].z+DP(j));//计算最大高度
    return dp[i];
}
int main(){
    for(int ii=1;~scanf("%d",&n)&&n!=0;++ii){
        blocks.clear();
        DAG.clear();
        while(n--){
            int a[3];
            scanf("%d%d%d",&a[0],&a[1],&a[2]);
            for(int i=0;i<3;++i)//找出所有可以摆放的立方体
                for(int j=0;j<3;++j)
                    for(int k=0;k<3;++k)
                        if(i!=j&&i!=k&&j!=k)
                            blocks.push_back(Block(a[i],a[j],a[k]));
        }
        DAG.resize(blocks.size());
        for(int i=0;i<DAG.size();++i)//建立DAG图
            for(int j=0;j<DAG.size();++j)
                if(blocks[i].x<blocks[j].x&&blocks[i].y<blocks[j].y)
                    DAG[i].push_back(j);
        int ans=0;
        for(int i=0;i<blocks.size();++i){//计算出以各节点为起点的最大高度，并求出这些最大高度中的最大高度
            memset(dp,0,sizeof(dp));
            ans=max(ans,DP(i));
        }
        printf("Case %d: maximum height = %d\n",ii,ans);
    }
    return 0;
}
