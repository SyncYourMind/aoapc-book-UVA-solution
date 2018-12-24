#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)//for循环的一种简单写法的宏定义
using namespace std;
int main(){
    int r,c;
    char puzzle[10][10];//存储网格
    scanf("%d",&r);
    for(int n=1;r>0;++n){
        scanf("%d",&c);
        vector<pair<int,int>>num;//存储起始格的位置，数组下标+1代表起始格序号
        if(n>1)
            puts("");//输出两个Puzzle之间的空行
        _for(i,0,r){
            getchar();//吸收换行符
            _for(j,0,c){
                puzzle[i][j]=getchar();//获取字符
                //判断是否是起始格
                if(puzzle[i][j]!='*'&&(i==0||j==0||puzzle[i-1][j]=='*'||puzzle[i][j-1]=='*'))
                    num.push_back({i,j});
            }
        }
        vector<bool>visit(num.size(),false);//标记一个起始格是否已被访问过
        printf("puzzle #%d:\nAcross\n",n);
        _for(i,0,num.size()){//横向输出单词
            if(!visit[i]){
                printf(" %s%d.",i<9?" ":"",i+1);
                for(int j=num[i].second;j<c&&puzzle[num[i].first][j]!='*';++j){
                    putchar(puzzle[num[i].first][j]);
                    //如果当前处理的格子是起始格，在num中找到该起始格的下标并置对应的visit元素为true
                    auto t=find(num.begin(),num.end(),make_pair(num[i].first,j))-num.begin();
                    if(t<num.size())
                        visit[t]=true;
                }
                puts("");
            }
        }
        puts("Down");//纵向输出单词
        fill(visit.begin(),visit.end(),false);
        _for(i,0,num.size()){
            if(!visit[i]){
                printf(" %s%d.",i<9?" ":"",i+1);
                for(int j=num[i].first;j<r&&puzzle[j][num[i].second]!='*';++j){
                    putchar(puzzle[j][num[i].second]);
                    auto t=find(num.begin(),num.end(),make_pair(j,num[i].second))-num.begin();
                    if(t<num.size())
                        visit[t]=true;
                }
                puts("");
            }
        }
        scanf("%d",&r);
    }
    return 0;
}
