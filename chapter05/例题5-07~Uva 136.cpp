#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a[3]={2,3,5},ans=0;
    set<long long>s;
    priority_queue<long long,vector<long long>,greater<long long>>pq;//用小顶堆实现的优先级队列
    pq.push(1);
    s.insert(1);
    for(int i=0;i<1500;++i){
        ans=pq.top();
        pq.pop();
        for(int j=0;j<3;++j)
            if(s.find(a[j]*ans)==s.end()){//该丑数未被生成过
                s.insert(a[j]*ans);
                pq.push(a[j]*ans);
            }
    }
    printf("The 1500'th ugly number is %d.\n",ans);
    return 0;
}
