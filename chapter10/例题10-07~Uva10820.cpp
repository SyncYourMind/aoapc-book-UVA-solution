#include<bits/stdc++.h>
using namespace std;
vector<int>phi(50005,0);
void phi_table(int n) {
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
        if(phi[i]==0)
            for(int j = i; j <= n; j += i) {
                if(phi[j]==0)
                    phi[j] = j;
                phi[j] = phi[j] / i * (i-1);
            }
}
int main(){
    phi_table(phi.size()-1);
    for(int i=2;i<phi.size();++i)
        phi[i]=phi[i]*2+phi[i-1];
    int n;
    while(~scanf("%d",&n)&&n!=0)
        printf("%d\n",phi[n]);
    return 0;
}
