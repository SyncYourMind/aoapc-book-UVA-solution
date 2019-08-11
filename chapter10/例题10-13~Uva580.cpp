#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>ans={0,0,0,1};
    for(int n=4;n<=30;++n){
        ans.push_back(1<<(n-3));
        for(int i=2;i<=n-2;++i)
            ans.back()+=((1<<(i-2))-ans[i-2])*(1<<(n-i-2));
    }
    int n;
    while(cin>>n&&n!=0)
        cout<<ans[n]<<endl;
    return 0;
}
