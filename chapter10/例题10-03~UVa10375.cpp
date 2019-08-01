#include<bits/stdc++.h>
using namespace std;
vector<int>prime;//素数表存储在prime中，prime是全局变量
void findPrime(int n){//欧拉筛法求素数表
    vector<bool>f(n,true);//i为素数，则f[i]=true;i不是素数，则f[i]=false
    for(int i=2;i<n;++i){
        if(f[i])
            prime.push_back(i);
        for(int j=0;j<prime.size()&&i*prime[j]<n;++j){//遍历所有已筛选出的素数
            f[i*prime[j]]=false;//i*prime[j]不是素数
            if(i%prime[j]==0)//关键
                break;
        }
    }
}
unordered_map<int,int>factor;//质因子在factor中，键表示质因子，值表示该质因子个数
void getFactor(int n,int arg){
    for(int i:prime){
        while(n%i==0){
            factor[i]+=arg;
            n/=i;
        }
        if(n==1)
            break;
    }
}
void resolve(int n,int arg){
    for(int i=2;i<=n;++i)
        getFactor(i,arg);
}
int main(){
    findPrime(10001);//打印2~10000以内的素数表存储到prime中
    int p,q,r,s;
    while(~scanf("%d%d%d%d",&p,&q,&r,&s)){
        factor.clear();
        vector<int>v={p,r-s,s,p-q,q,r};
        for(int i=0;i<v.size();++i)
            resolve(v[i],i<3?1:-1);
        double ans=1.0;
        for(auto&i:factor)
            ans*=pow(i.first,i.second);
        printf("%.5f\n",ans);
    }
    return 0;
}
