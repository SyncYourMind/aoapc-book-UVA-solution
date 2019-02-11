#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n!=0){
        vector<vector<int>>graph(n+1);
        int a,b,degree[n+1]={0};
        while(m--){
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            ++degree[b];//递增结点的入度
        }
        queue<int>q;//储存入度为零的结点
        bool space=false;
        for(int i=1;i<=n;++i)//将入度为零的结点放入队列中
            if(degree[i]==0)
                q.push(i);
        while(!q.empty()){//队列不空
            int p=q.front();//弹出队首结点
            q.pop();
            printf("%s%d",space?" ":"",p);//输出该结点
            space=true;
            for(int i:graph[p])//遍历该结点能到达的结点
                if(--degree[i]==0)//减少能到达结点的入度，如果入度为零
                    q.push(i);//压入队列
        }
        puts("");
    }
    return 0;
}
