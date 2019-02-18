#include<bits/stdc++.h>
using namespace std;
int T,n,t,length[55];
pair<int,int>dp[55][180*55+678];
int main(){
    scanf("%d",&T);
    for(int ii=1;ii<=T;++ii){
        scanf("%d%d",&n,&t);
        for(int i=0;i<n;++i)
            scanf("%d",&length[i]);
        for(int i=0;i<=t;++i)//边界
            dp[n-1][i]=(i>length[n-1])?make_pair(2,length[n-1]+678):make_pair(1,678);
        for(int i=n-2;i>=0;--i)
            for(int j=0;j<=t;++j){
                dp[i][j]=dp[i+1][j];
                if(j>length[i])
                    dp[i][j]=max(dp[i][j],{dp[i+1][j-length[i]].first+1,dp[i+1][j-length[i]].second+length[i]});
            }
        printf("Case %d: %d %d\n",ii,dp[0][t].first,dp[0][t].second);
    }
    return 0;
}
