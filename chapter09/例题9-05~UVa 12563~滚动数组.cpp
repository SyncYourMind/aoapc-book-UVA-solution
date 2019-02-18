#include<bits/stdc++.h>
using namespace std;
int T,n,t,a;
pair<int,int>dp[180*55+678];
int main(){
    scanf("%d",&T);
    for(int ii=1;ii<=T;++ii){
        scanf("%d%d",&n,&t);
        for(int i=0;i<=t;++i)//初始化dp数组
            dp[i]={1,678};
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            for(int j=t;j>=0;--j)
                if(j>a)
                    dp[j]=max(dp[j],{dp[j-a].first+1,dp[j-a].second+a});
        }
        printf("Case %d: %d %d\n",ii,dp[t].first,dp[t].second);
    }
    return 0;
}
