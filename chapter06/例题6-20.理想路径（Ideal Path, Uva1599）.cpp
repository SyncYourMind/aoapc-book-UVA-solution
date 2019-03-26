#include<bits/stdc++.h>
using namespace std;
int ID(char c1,char c2){//将A+～Z+，A-～Z-这52种标记转换为0~51这52个顶点编号
    return (c1-'A')*2+(c2=='+'?0:1);
}
int main(){
    int n;
    string s;
    while(cin>>n){
        vector<vector<int>>graph(52);//图
        vector<int>degree(52);//各个顶点的入度
        while(n--){
            cin>>s;
            for(int i=0;i<8;i+=2)
                for(int j=0;j<8;j+=2)
                    if(i!=j&&s[i]!='0'&&s[j]!='0'){
                        int a=ID(s[i],s[i+1]),b=ID(s[j],s[j+1]);//转换成两个顶点编号
                        graph[a^1].push_back(b);//插入边
                        ++degree[b];//递增b号顶点的入度
                    }
        }
        int num=0;//拓扑序列中的顶点数目
        queue<int>q;//储存入度为零的结点
        for(int i=0;i<52;++i)//将入度为零的结点放入队列中
            if(degree[i]==0)
                q.push(i);
        while(!q.empty()){//队列不空
            int p=q.front();//弹出队首结点
            q.pop();
            ++num;
            for(int i:graph[p])//遍历该结点能到达的结点
                if(--degree[i]==0)//减少能到达结点的入度，如果入度为零
                    q.push(i);//压入队列
        }
        puts(num==52?"bounded":"unbounded");//拓扑序列顶点数目等于52时表示无环
    }
    return 0;
}
