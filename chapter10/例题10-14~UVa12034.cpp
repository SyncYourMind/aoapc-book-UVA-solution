#include<bits/stdc++.h>
using namespace std;
int C[1005][1005],mod=10056;
int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<=1000;++i){//求出所有组合数
        C[i][0]=1;
        for(int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    vector<int>ans(1001,1);
    for(int n=2;n<=1000;++n)//求出f(1)~f(1000)
        for(int i=1;i<n;++i)
            ans[n]=(ans[n]+(C[n][i]%mod)*ans[n-i])%mod;
    for(int ii=1;cin>>n;++ii)
        printf("Case %d: %d\n",ii,ans[n]);
    return 0;
}
