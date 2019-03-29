#include<bits/stdc++.h>
using namespace std;
struct Patch{//补丁
    int time;
    char s1[25],s2[25];
};
typedef pair<int,int> pis;
bool match(const bitset<32>&b,const Patch&p){//当前状态与补丁是否匹配
    for(int i=0;p.s1[i]!='\0';++i)
        if((p.s1[i]=='+'&&!b[i])||(p.s1[i]=='-'&&b[i]))
            return false;
    return true;
}
int fix(bitset<32>&b,const Patch&p){//打补丁，返回打好补丁后的状态
    for(int i=0;i<p.s2[i]!='\0';++i){
        if(p.s2[i]=='+')
            b[i]=true;
        else if(p.s2[i]=='-')
            b[i]=false;
    }
    return b.to_ulong();
}
int main(){
    int n,m;
    for(int ii=1;~scanf("%d%d",&n,&m)&&n!=0;++ii){
        vector<Patch>patches(m);//存储所有的补丁
        for(int i=0;i<m;++i)
            scanf("%d%s%s",&patches[i].time,patches[i].s1,patches[i].s2);
        unordered_map<int,int>dis={{(1<<n)-1,0}};//存储状态及对应花费的最短时间
        priority_queue<pis,vector<pis>,greater<pis>>pq;
        pq.push({0,(1<<n)-1});
        while(!pq.empty()){//Dijkstra算法
            pis t=pq.top();
            pq.pop();
            if(dis[t.second]!=t.first)
                continue;
            for(Patch p:patches){
                bitset<32>b(t.second);
                if(match(b,p)){
                    int s=fix(b,p);
                    if(dis.find(s)==dis.end()||dis[s]>t.first+p.time){
                        dis[s]=t.first+p.time;
                        pq.push({t.first+p.time,s});
                    }
                }
            }
        }
        printf("Product %d\n",ii);
        if(dis.find(0)!=dis.end())
            printf("Fastest sequence takes %d seconds.\n\n",dis[0]);
        else
            printf("Bugs cannot be fixed.\n\n");
    }
    return 0;
}
