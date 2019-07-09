#include<bits/stdc++.h>
using namespace std;
int n;
double dp[55][55],x[55],y[55],dist[55][55];
int main(){
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;++i)
            scanf("%lf%lf",&x[i],&y[i]);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        for(int i=1;i<n-1;++i)//边界情况
            dp[n-1][i]=dist[n-1][n]+dist[i][n];
        for(int i=n-2;i>1;--i)
            for(int j=1;j<i;++j)
                dp[i][j]=min(dist[i+1][i]+dp[i+1][j],dist[i+1][j]+dp[i+1][i]);
        printf("%.2f\n",dp[2][1]+dist[2][1]);
    }
    return 0;
}
