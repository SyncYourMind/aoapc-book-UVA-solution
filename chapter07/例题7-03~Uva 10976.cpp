#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    while(cin>>k){
        vector<pair<int,int>>v;
        for(int i=k+1;i<=k+k;++i)
            if(i*k%(i-k)==0)//分母对分子的余数为0
                v.push_back({i*k/(i-k),i});//找到了一组满足条件的x与y
        printf("%d\n",v.size());
        for(auto&i:v)
            printf("1/%d = 1/%d + 1/%d\n",k,i.first,i.second);
    }
    return 0;
}
