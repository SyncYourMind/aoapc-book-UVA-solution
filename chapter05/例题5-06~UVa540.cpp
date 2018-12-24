#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int t,ii=1;~scanf("%d",&t)&&t!=0;++ii){
        printf("Scenario #%d\n",ii);
        queue<int>q;//按每一个团队第一个到达的队员的顺序存储每个团队的队号
        vector<queue<int>>teamPerson(t);//按队中先来后到顺序存储正在排队的每个团队中队员
        unordered_map<int,int>belongTeam;//存储每个编号的队员对应的队号
        int num,a;
        for(int i=0;i<t;++i){//读取每个团队队员，团队编号从0开始逐渐递增
            scanf("%d",&num);
            while(num--){
                scanf("%d",&a);
                belongTeam[a]=i;//a号队员属于i号团队
            }
        }
        string command;
        while(cin>>command&&command!="STOP")//命令command是STOP时跳出循环
            if(command=="ENQUEUE"){//入队
                scanf("%d",&a);//读取入队队员编号
                if(teamPerson[belongTeam[a]].empty())//入队队员所在团队无人在排队
                    q.push(belongTeam[a]);//该团队位于排在最后一位
                teamPerson[belongTeam[a]].push(a);//该入队队员排序所属团队最后
            }else{
                printf("%d\n",teamPerson[q.front()].front());//输出出队队员编号
                teamPerson[q.front()].pop();//弹出队伍最前的队员
                if(teamPerson[q.front()].empty())//如果长队最前的团队没有人排队了
                    q.pop();//将最前面的队伍弹出长队
            }
        puts("");//输出空行
    }
    return 0;
}
