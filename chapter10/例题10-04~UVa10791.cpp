#include<bits/stdc++.h>
using namespace std;
long long f(long long m){
    long long ans=0,n=m;
    for(int i=2;i<=(int)sqrt(n*1.0);++i){
        int j=1;
        for(;n%i==0;n/=i)
            j*=i;
        ans+=(j==1)?0:j;//j==1表示i不能整除n
    }
    return (ans==0||m==ans)?m+1:n==1?ans:ans+n;
}
int main(){
    long long n;
    for(int ii=1;~scanf("%lld",&n)&&n!=0;++ii){
        long long ans=f(n);
        printf("Case %d: %lld\n",ii,ans);
    }
    return 0;
}
