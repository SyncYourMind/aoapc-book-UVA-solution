#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
int main(){
    char puzzle[5][5];
    int emptyi,emptyj;//空白方格的横纵坐标
    for(int k=1;true;++k){//k表示第几场puzzle游戏
        _for(i,0,5){
            _for(j,0,5){
                puzzle[i][j]=getchar();//读取整个puzzle
                if(puzzle[0][0]=='Z')//读取到了Z字符，直接结束游戏
                    goto loop;
                if(puzzle[i][j]==' '){//读取到了空白字符，确定空白方格的横纵坐标
                    emptyi=i;
                    emptyj=j;
                }
            }
            getchar();//读取后面的换行符
        }
        if(k>1)
            puts("");//输出每两个Puzzle之间的空行，注意最后一个Puzzle后没有空行
        printf("Puzzle #%d:\n",k);
        bool f=true;//表示有没有最终的puzzle
        for(char c=getchar();c!='0';c=getchar()){//读取到字符0才算结束
            int tempi=emptyi,tempj=emptyj;
            if(c=='A'&&emptyi>0)
                --emptyi;
            else if(c=='B'&&emptyi<4)
                ++emptyi;
            else if(c=='L'&&emptyj>0)
                --emptyj;
            else if(c=='R'&&emptyj<4)
                ++emptyj;
            else if(c!='\n')//略过换行符
                f=false;
            if(f)
                swap(puzzle[tempi][tempj],puzzle[emptyi][emptyj]);//交换两个字符
        }
        if(f){
            _for(i,0,5){//输出整个puzzle
                _for(j,0,5)
                    printf("%c%s",puzzle[i][j],j<4?" ":"");
                puts("");
            }
        }else
            puts("This puzzle has no final configuration.");
        getchar();//读取后面的换行符
    }
loop:
    return 0;
}
