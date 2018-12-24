#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)//for循环的一种简单写法的宏定义
using namespace std;
int main(){
    int n,d;
    while(~scanf("%d%d",&n,&d)){
        printf("%d/%d = %d.",n,d,n/d);
        n=n%d*10;//余数作为下一次的被除数
        vector<pair<int,int>>v;
        auto start=INT_MAX;//存储循环最前的小数所在位置
        while(start==INT_MAX){
            v.push_back({n,n/d});
            n=n%d*10;//余数作为下一次的被除数
            _for(i,0,v.size())//查看现在的余数是否在被除数出现过
                if(v[i].first==n){
                    start=i;
                    break;
                }
        }
        _for(i,0,start)
            printf("%d",v[i].second);
        printf("(");
        _for(i,start,min((int)v.size(),start+50))
            printf("%d",v[i].second);
        printf("%s)\n",v.size()>start+50?"...":"");
        printf("   %d = number of digits in repeating cycle\n\n",v.size()-start);
    }
    return 0;
}
