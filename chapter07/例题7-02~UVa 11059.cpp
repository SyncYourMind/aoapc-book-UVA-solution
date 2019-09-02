#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a[20];
    for (int ii = 1; cin >> n; ++ii) {
        for(int i=0;i<n;++i)
            cin>>a[i];
        long long ans=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                long long p=1;
                for(int k=i;k<=j;++k)
                    p*=a[k];
                ans=max(ans,p);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ii, ans);
    }
    return 0;
}
