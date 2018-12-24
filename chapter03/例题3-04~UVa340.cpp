#include<bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);++i)//for循环的一种用宏表示的简写方式
void readData(int*sequence,int*frequency,int N){//读入数据并统计序列中每个数字出现的频率
    fill(frequency,frequency+10,0);
    _for(i,0,N){
        scanf("%d",&sequence[i]);
        ++frequency[sequence[i]];
    }
}
int main(){
    int N,num=0,code[1005],guess[1005],codeFre[10],guessFre[10],codeFreCopy[10];
    scanf("%d",&N);
    while(N!=0){//N不为0继续游戏
        printf("Game %d:\n",++num);
        readData(code,codeFre,N);//读取答案序列
        readData(guess,guessFre,N);//读取猜的序列
        while(guessFre[0]<N){//猜的序列如果数字全为0的话，那么猜的序列0出现的频率就是N，可以用这一点作为一次游戏是否结束的标志
            memcpy(codeFreCopy,codeFre,sizeof(codeFre));//将codeFre数组元素拷贝到codeFreCopy中
            int strong=0,weak=0;
            _for(i,0,N)//统计两个序列中数字相同且位置相同的数字个数strong
                if(code[i]==guess[i]){
                    ++strong;
                    --codeFreCopy[code[i]];
                    --guessFre[guess[i]];
                }
            _for(i,0,10) weak+=min(guessFre[i],codeFreCopy[i]);//统计数字相同但位置不同的数字个数weak
            printf("    (%d,%d)\n",strong,weak);//输出，注意每行前要输出4个空格
            readData(guess,guessFre,N);//再次读入猜的序列
        }
        scanf("%d",&N);//读取N
    }
    return 0;
}
