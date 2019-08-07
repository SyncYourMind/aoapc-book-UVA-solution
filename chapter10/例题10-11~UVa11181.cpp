#include<bits/stdc++.h>
using namespace std;
double p[25],ans[25],sum=0.0;
int N,r;
vector<int>Select;//存储r个买了东西的人的编号
void DFS(int i,double pcur){
    if(i==N){//n个人枚举完成
        if(Select.size()==r){//r个人买了东西
            for(int i:Select)
                ans[i]+=pcur;
            sum+=pcur;
        }
        return;
    }
    Select.push_back(i);
    DFS(i+1,pcur*p[i]);//当前编号为i的人买了东西
    Select.pop_back();
    DFS(i+1,pcur*(1-p[i]));//当前编号为i的人没买东西
}
int main(){
    for(int ii=1;cin>>N>>r&&N!=0;++ii){
        printf("Case %d:\n",ii);
        memset(ans,0,sizeof(ans));
        sum=0.0;
        for(int i=0;i<N;++i)
            cin>>p[i];
        DFS(0,1.0);
        for(int i=0;i<N;++i)
            printf("%.6f\n",ans[i]/sum);
    }
    return 0;
}
