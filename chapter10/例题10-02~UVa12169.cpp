#include<bits/stdc++.h>
using namespace std;
int x[205],T,m=10001;
bool f(int a,int b){
    for (int i=2;i<2*T+1;++i)
        if(i%2==0)
            x[i]=(x[i-1]*a+b)%m;
        else if(x[i]!=(x[i-1]*a+b)%m)
            return false;
    return true;
}
int main(){
    scanf("%d",&T);
    for(int i=1;i<2*T+1;i+=2)
        scanf("%d",&x[i]);
    for (int a=0;a<m;++a)
        for (int b=0;b<m;++b)
            if(f(a,b)){
                for (int i=2;i<2*T+1;i+=2)
                    printf("%d\n",x[i]);
                goto loop;
            }
loop:return 0;
}
