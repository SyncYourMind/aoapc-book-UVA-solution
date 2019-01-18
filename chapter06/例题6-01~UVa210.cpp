#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,n,t[5],Q;
    scanf("%d%*c",&N);
    for(int ii=0;ii<N;++ii){
        if(ii>0)
            puts("");
        scanf("%*c%d%d%d%d%d%d%d%*c",&n,&t[0],&t[1],&t[2],&t[3],&t[4],&Q);
        unordered_map<char,int>variable;//变量与其值的映射关系
        deque<int>block,wait;//阻塞队列、等待队列
        bool lock=false;//锁
        vector<deque<string>>program(n+1);//每个程序
        for(int i=1;i<=n;++i){//读取每个程序代码
            wait.push_back(i);//。初始等待队列包含按输入顺序排列的各个程序
            string line;
            while(getline(cin,line)&&line!="end")
                program[i].push_back(line);
            program[i].push_back("end");
        }
        while(!wait.empty()){//等待队列不空就继续循环
            int cur=wait.front();//读取当前运行的程序
            wait.pop_front();
            if(program[cur].empty())//当前程序已运行完毕，不再执行任何操作
                continue;
            wait.push_back(cur);//将当前运行的程序插入到等待队列末尾
            for(int time=0;time<Q;){//当前程序运行时间小于配额时继续执行
                string s=program[cur].front();//读取需要执行的指令
                program[cur].pop_front();//弹出队首指令
                if(s[2]=='='){//是赋值指令
                    variable[s[0]]=stoi(s.substr(4));//更新或插入变量及其对应值
                    time+=t[0];//更新当前程序运行时间
                }else if(s[2]=='i'){//是print指令
                    printf("%d: %d\n",cur,variable[s[6]]);//打印
                    time+=t[1];//更新当前程序运行时间
                }else if(s[2]=='c'){//是lock指令
                    if(lock){//已经上锁了
                        program[cur].push_front(s);//当前指令重新压回队首
                        block.push_back(cur);//当前程序插入到阻塞队列队尾
                        wait.pop_back();//将当前程序从等待队列末尾中删除
                        break;//不再执行其他指令
                    }//没有上锁过
                    lock=true;//上锁
                    time+=t[2];//更新当前程序运行时间
                }else if(s[2]=='l'){//unlock指令
                    lock=false;//解除上锁
                    time+=t[3];//更新当前程序运行时间
                    if(!block.empty()){//阻塞队列不空
                        wait.push_front(block.front());//将阻塞队列队首程序插入到等待队列队首
                        block.pop_front();//弹出阻塞队列队首程序
                    }
                }else if(s[2]=='d')//end指令
                    break;//直接跳出循环
            }
        }
    }
    return 0;
}
