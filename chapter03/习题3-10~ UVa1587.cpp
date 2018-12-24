#include<bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        unordered_map<int,int>m;
        map<pair<int,int>,int>mp;
        for(int i=0;i<6;++i){
            int k1,k2;
            if(scanf("%d%d",&k1,&k2)==EOF)
                goto loop;
            ++m[k1];
            ++m[k2];
            ++mp[make_pair(max(k1,k2),min(k1,k2))];
        }
        for(auto&i:m)
            if(i.second%4!=0){
                puts("IMPOSSIBLE");
                goto loop2;
            }
        for(auto&i:mp)
            if(i.second%2!=0){
                puts("IMPOSSIBLE");
                goto loop2;
            }
        puts("POSSIBLE");
loop2:;
    }
loop:
    return 0;
}
