#include<bits/stdc++.h>
using namespace std;
struct Player{//选手类
    string playername="";//姓名
    int RD[4]={-1,-1,-1,-1};//四轮成绩
    int total=-1;//四轮成绩之和
    int place=1;//排名
    int roundNum=0;//参加的比赛轮数，例如前两轮没有犯规，第三轮犯规，则roundNum=3
    double money=0.0;//获得奖金
    bool amateur=false;//是否是业余选手
    bool T=false;//是否需要在排名后输出'T'
    bool prize=false;//是否可以拿到奖金
};
int main(){
    int N;
    scanf("%d",&N);//数据组数
    double purse[71]={0.0};//奖金比例，purse[0]存储总奖金额
    int playerNumber;//选手人数
    for(int ii=0;ii<N;++ii){
        if(ii>0)//每两组测试数据之间输出一个空行
            puts("");
        scanf("%lf",&purse[0]);//读取总奖金额
        for(int i=1;i<71;++i)//读取奖金比例
            scanf("%lf",&purse[i]);
        scanf("%d%*c",&playerNumber);//读取选手人数，%*c吸收换行符
        Player players[playerNumber];
        string line;
        for(int i=0;i<playerNumber;++i){//读取每个选手的信息
            getline(cin,line);//读取整行字符
            //如果整行字符中有'*'字符，表明是业余选手
            players[i].amateur=(find(line.begin(),line.end(),'*')!=line.end());
            //分割选手姓名，注意这里直接读取了21个字符，因为输出姓名时也需要输出21个字符
            players[i].playername=line.substr(0,21);
            players[i].total=0;
            for(int j=0;j<4;++j){//分割4轮成绩
                string t=line.substr(21+j*3,2);//分割成绩
                if(t=="DQ")//犯规，直接跳出循环
                    break;
                ++players[i].roundNum;//递增参加的比赛轮数
                players[i].RD[j]=stoi(t);//读取该轮成绩
            }
            //先取前两轮成绩之和，如果前两轮有犯规，将成绩之和置为400，因为成绩越小排名越靠前，置为400可以保证犯规选手排序后位于末尾
            players[i].total=(players[i].roundNum<2)?400:players[i].RD[0]+players[i].RD[1];
        }
        sort(players,players+playerNumber,[](const Player&p1,const Player&p2){//按成绩由小到大排序
            return p1.total<p2.total;
        });
        playerNumber=70;//晋级选手人数初始化为70
        //如果有和70名选手相同成绩的，递增晋级选手人数
        while(players[playerNumber].total==players[69].total)
            ++playerNumber;
        for(int i=0;i<playerNumber;++i){//计算每位晋级选手的4轮成绩之和，犯规成绩不计入
            if(players[i].RD[2]!=-1)
                players[i].total+=players[i].RD[2];
            if(players[i].RD[3]!=-1)
                players[i].total+=players[i].RD[3];
        }
        sort(players,players+playerNumber,[](const Player&p1,const Player&p2){//排序
            if(p1.roundNum!=p2.roundNum)//先按比赛轮数由大到小排序
                return p1.roundNum>p2.roundNum;
            else if(p1.total!=p2.total)//接着按成绩之和有小到大排序
                return p1.total<p2.total;
            else//最后按姓名排序
                return p1.playername<p2.playername;
        });
        int purseIndex=1;//当前分配的奖金比例索引
        for(int i=0;i<playerNumber;){//遍历每一个晋级选手
            int j=i,profession=0;//profession为与当前选手成绩相同的专业选手人数
            for(;j<playerNumber&&players[j].total==players[i].total;++j){//遍历与当前当前选手成绩相同的选手
                if(!players[j].amateur){//是专业选手
                    ++profession;//递增profession
                    players[j].prize=(purseIndex<=70);//是否获奖取决于是否还有未分配的奖金比例
                }
            }
            double currentPurse=0.0;
            //统计与当前选手成绩相同的专业选手获取的奖金比例总和
            for(int k=0;k<profession&&purseIndex<=70;++k)
                currentPurse+=purse[purseIndex++];
            currentPurse*=purse[0]/100/profession;//计算每一位专业选手获得的奖金额
            for(int k=i;k<j;++k){//遍历与当前当前选手成绩相同的选手
                players[k].place=i+1;//更新当前选手排名
                players[k].money=players[k].prize?currentPurse:0.0;//计算获取的奖金额
                //当且仅当当前选手是专业选手且有并列的专业选手且可以获奖时，才需要在排名后输出'T'
                players[k].T=!players[k].amateur&&profession>1&&players[k].prize;
            }
            i=j;
        }
        puts("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won");
        puts("-----------------------------------------------------------------------");
        for(int i=0;i<playerNumber;++i){//遍历每一个晋级选手
            string place="";//输出的排名字符串
            if(players[i].roundNum==4)//如果参加了4轮比赛，才需要输出排名
                place=to_string(players[i].place)+((players[i].T)?"T":"");
            printf("%s%-10s",players[i].playername.c_str(),place.c_str());//输出姓名和排名
            for(int j=0;j<4;++j)//输出4轮成绩
                if(players[i].RD[j]==-1)//没有该轮成绩
                    printf("     ");//输出5个空格符
                else
                    printf("%-5d",players[i].RD[j]);//成绩占5个字符，左对齐
            if(players[i].roundNum<4)//选手有犯规
                printf("DQ");//输出"DQ"
            else if(players[i].amateur||!players[i].prize)//选手是业余选手或者没有获奖的专业选手
                printf("%d",players[i].total);//只输出成绩总和
            else//否则输出成绩总和以及获得的奖金
                printf("%-10d$%9.2f",players[i].total,players[i].money);
            puts("");//换行
        }
    }
    return 0;
}
