#include<bits/stdc++.h>
using namespace std;
int n;
double dp[55][55],x[55],y[55],dist[55][55];
double DP(int i,int j){
    if(dp[i][j]!=-1.0)
        return dp[i][j];
    if(i==n-1)
        return dp[i][j]=dist[i][n]+dist[j][n];
    return dp[i][j]=min(dist[i+1][i]+DP(i+1,j),dist[i+1][j]+DP(i+1,i));
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;++i)
            scanf("%lf%lf",&x[i],&y[i]);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){
                dp[i][j]=-1.0;
                dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            }
        printf("%.2f\n",DP(2,1)+dist[2][1]);
    }
    return 0;
}
