#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,op,x,y;
    for(int ii=1;~scanf("%d%d",&n,&m);++ii){
        list<int>line(n);//链表
        vector<list<int>::iterator>it(n+1);//存储迭代器的数组
        bool r=false;//标志是否需要翻转链表
        auto i=line.begin();
        for(int j=1;j<=n;++j){//初始化链表line和存储迭代器的数组it
            *i=j;
            it[j]=i++;
        }
        while(m--){
            scanf("%d",&op);
            if(op==4){//指令4，只需更改r，不需要真的翻转链表
                r=!r;
                continue;
            }
            scanf("%d%d",&x,&y);
            if(op==3){//指令3，交换x和y元素
                swap(*it[x],*it[y]);
                swap(it[x],it[y]);
                continue;
            }
            auto yLeft=it[y],yRight=it[y];//找到指向y左边元素和y右边元素的迭代器
            --yLeft;
            ++yRight;
            if(r)//需要翻转链表
                op=3-op;//指令1变为指令2，指令2变为指令1
            if(op==1&&it[x]!=yLeft){//指令1且x没有在y的左边
                line.erase(it[x]);//在链表中删除x
                it[x]=line.insert(it[y],x);//在y左边插入元素x
            }else if(op==2&&it[x]!=yRight){//指令2且x没在y的右边
                line.erase(it[x]);//在链表中删除x
                it[x]=line.insert(yRight,x);//在y右边插入元素x
            }
        }
        long long ans=0;//存储结果
        if(r)//需要翻转链表
            line.reverse();
        i=line.begin();
        for(int j=1;j<=n;++j,++i)
            if(j%2==1)
                ans+=*i;
        printf("Case %d: %lld\n",ii,ans);
    }
    return 0;
}
