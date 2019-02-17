#include<bits/stdc++.h>
using namespace std;
int a[15][105],dp[15][105],path[15][105],r,c;
int main(){
    while(~scanf("%d%d",&r,&c)){
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                scanf("%d",&a[i][j]);
        for(int i=0;i<r;++i)//边界
            dp[i][c-1]=a[i][c-1];
        for(int j=c-2;j>=0;--j)
            for(int i=0;i<r;++i){
                dp[i][j]=INT_MAX;//置当前dp为最大值
                for(int k=-1;k<=1;++k){//遍历3种决策
                    int ii=(i+k+r)%r;//下一列的行号
                    if(dp[i][j]>dp[ii][j+1]+a[i][j]||(dp[i][j]==dp[ii][j+1]+a[i][j]&&ii<path[i][j])){
                        path[i][j]=ii;
                        dp[i][j]=dp[ii][j+1]+a[i][j];
                    }
                }
            }
        int ans=0;
        for(int i=0;i<r;++i)//求出最小路径的第一列的行号
            if(dp[i][0]<dp[ans][0])
                ans=i;
        printf("%d",ans+1);
        for(int i=1,j=path[ans][0];i<c;j=path[j][i++])
            printf(" %d",j+1);
        printf("\n%d\n",dp[ans][0]);
    }
    return 0;
}
