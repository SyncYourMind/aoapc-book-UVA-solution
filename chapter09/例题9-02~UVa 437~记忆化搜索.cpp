#include<bits/stdc++.h>
using namespace std;
struct Block{
    int x,y,z;//长宽高
    Block(int a,int b,int c):x(a),y(b),z(c){}
};
int n;
vector<Block>blocks;//存储所有可能摆放的立方体
int DP(int v,vector<int>&dp){
    if(dp[v]!=0)//该结点已计算过，直接返回值
        return dp[v];
    dp[v]=blocks[v].z;//dp数组初始化为对应立方体的高
    for(int i=0;i<blocks.size();++i)//遍历所有立方体
        if(blocks[i].x>blocks[v].x&&blocks[i].y>blocks[v].y)//当前遍历到的立方体长宽更大
            dp[v]=max(dp[v],blocks[v].z+DP(i,dp));//计算最大高度
    return dp[v];
}
int main(){
    for(int ii=1;~scanf("%d",&n)&&n!=0;++ii){
        blocks.clear();
        for(int i=0;i<n;++i){
            int a[3];
            scanf("%d%d%d",&a[0],&a[1],&a[2]);
            for(int i=0;i<3;++i)//找出所有可以摆放的立方体
                for(int j=0;j<3;++j)
                    for(int k=0;k<3;++k)
                        if(i!=j&&i!=k&&j!=k)
                            blocks.push_back(Block(a[i],a[j],a[k]));
        }
        int ans=0;
        vector<int>dp(blocks.size(),0);
        for(int i=0;i<blocks.size();++i)//计算出以各节点为起点的最大高度，并求出这些最大高度中的最大高度
            ans=max(ans,DP(i,dp));
        printf("Case %d: maximum height = %d\n",ii,ans);
    }
    return 0;
}
