#include<bits/stdc++.h>
using namespace std;
int N,T,m1,m2,t[55],dp[55][205];
bool hasTrain[55][205][2];
const int INF=(int)(1e9);
int main(){
    for(int ii=1;~scanf("%d",&N)&&N!=0;++ii){
        memset(hasTrain,0,sizeof(hasTrain));//将hasTrain数组均置为false
        scanf("%d",&T);
        for(int i=1;i<N;++i)
            scanf("%d",&t[i]);
        int a;
        scanf("%d",&m1);
        for(int i=0;i<m1;++i){
            scanf("%d",&a);
            for(int j=1;j<N;++j){//计算该列车到达每个站的时刻，并置hasTrain为true
                if(a<=T)
                    hasTrain[j][a][0]=true;
                a+=t[j];
            }
        }
        scanf("%d",&m2);
        for(int i=0;i<m2;++i){
            scanf("%d",&a);
            for(int j=N;j>1;--j){//计算该列车到达每个站的时刻，并置hasTrain为true
                if(a<=T)
                    hasTrain[j][a][1]=true;
                a+=t[j-1];
            }
        }
        for(int i=1;i<N;++i)//处理边界值
            dp[i][T]=INF;
        dp[N][T]=0;//终点
        for(int j=T-1;j>=0;--j)
            for(int i=1;i<=N;++i){
                dp[i][j]=dp[i][j+1]+1;//第一种决策
                if(i+1<=N&&j+t[i]<=T&&hasTrain[i][j][0])//第二种决策
                    dp[i][j]=min(dp[i][j],dp[i+1][j+t[i]]);
                if(i-1>=1&&j+t[i-1]<=T&&hasTrain[i][j][1])//第三种决策
                    dp[i][j]=min(dp[i][j],dp[i-1][j+t[i-1]]);
            }
        printf("Case Number %d: ",ii);
        if(dp[1][0]>=INF)
            puts("impossible");
        else
            printf("%d\n",dp[1][0]);
    }
    return 0;
}
