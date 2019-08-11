#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<long long>ans={0,0,0,1},pow2={1};
    for(int i=1;i<=30;++i)
        pow2.push_back(pow2.back()<<1);
    for(int n=4;n<=30;++n){
        ans.push_back(pow2[n-3]);
        for(int i=2;i<=n-2;++i)
            ans.back()+=(pow2[i-2]-ans[i-2])*pow2[n-i-2];
    }
    int n;
    while(cin>>n&&n!=0)
        cout<<ans[n]<<endl;
    return 0;
}
