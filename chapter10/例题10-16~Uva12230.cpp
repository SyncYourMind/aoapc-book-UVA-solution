#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d,p,l,v;
    for(int ii=1;cin>>n>>d&&d!=0;++ii){
        double ans=0.0,suml=0.0;
        for(int i=0;i<n;++i){
            cin>>p>>l>>v;
            ans+=2.0*l/v;
            suml+=l*1.0;
        }
        printf("Case %d: %.3f\n\n",ii,ans+d-suml);
    }
    return 0;
}
