#include<bits/stdc++.h>
using namespace std;
int powMod(unsigned long long a,unsigned long long n,int m){//求a^n%m
    if(n==0)
        return 1;
    int x=powMod(a,n/2,m);
    long long ans=x*1ll*x%m;
    if(n%2==1)
        ans=ans*a%m;
    return (int)ans;
}
int main(){
    vector<vector<int>>mod(1005);//存储斐波那契数列对2~1005的余数
    for(int i=2;i<mod.size();++i){//求斐波那契数列对2~1005的余数
        auto&f=mod[i];
        f={0,1};//初始化为f[0]=0,f[1]=1
        while(true){
            int temp=(f.back()+f[f.size()-2])%i;//求出下一个斐波那契数对i的余数
            if(f.back()==0&&temp==1){//连续出现0,1，余数循环开始
                f.pop_back();//把末尾的0弹出，那么f就表示对i求余的一个完整的余数循环
                break;
            }
            f.push_back(temp);
        }
    }
    int t,n;
    scanf("%d",&t);
    unsigned long long a,b;
    while(t--){
        scanf("%llu%llu%d",&a,&b,&n);
        if(a==0||n==1){//a=0或n=1时，直接输出0
            puts("0");
            continue;
        }
        int index=powMod(a%mod[n].size(),b,mod[n].size());
        printf("%d\n",mod[n][index]);
    }
    return 0;
}
