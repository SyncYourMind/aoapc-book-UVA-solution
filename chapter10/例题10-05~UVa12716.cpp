#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v(30000005,0);
    for(int c=1;c<v.size();++c){
        for(int a=c*2;a<v.size();a+=c){
            if((a^(a-c))==c)
                ++v[a];
        }
    }
    for(int i=1;i<v.size();++i)
        v[i]+=v[i-1];
    int T,n;
    scanf("%d",&T);
    for(int ii=1;ii<=T;++ii){
        scanf("%d",&n);
        printf("Case %d: %d\n",ii,v[n]);
    }
    return 0;
}
