#include<bits/stdc++.h>
using namespace std;
int T,n,t,length[55];
pair<int,int>dp[55][180*55+678];
pair<int,int> DP(int i,int j){
    if(dp[i][j].first!=-1)//该dp数组已经访问过，直接返回值
        return dp[i][j];
    if(i==n-1)//边界情况
        return dp[i][j]=(j>length[i])?make_pair(2,length[i]+678):make_pair(1,678);
    dp[i][j]=DP(i+1,j);
    if(j>length[i])
        dp[i][j]=max(DP(i+1,j),{DP(i+1,j-length[i]).first+1,DP(i+1,j-length[i]).second+length[i]});
    return dp[i][j];
}
int main(){
    scanf("%d",&T);
    for(int ii=1;ii<=T;++ii){
        scanf("%d%d",&n,&t);
        for(int i=0;i<n;++i)
            scanf("%d",&length[i]);
        for(int i=0;i<n;++i)//对dp数组初始化
            for(int j=0;j<=t;++j)
                dp[i][j]={-1,-1};
        printf("Case %d: %d %d\n",ii,DP(0,t).first,DP(0,t).second);
    }
    return 0;
}
