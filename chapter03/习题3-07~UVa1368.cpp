#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)//for循环的一种简单写法的宏定义
using namespace std;
int main(){
    int T,m,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&n);
        string input[m];
        _for(i,0,m) cin>>input[i];//读入m个字符串
        map<char,int>um;//存储m个字符串中相同位置出现的字符及其对应的次数,注意map按键有小到大的顺序存储
        int error=0;//存储Hamming距离和
        _for(i,0,n){
            _for(j,0,m) ++um[input[j][i]];
            char MAX='A';
            for(auto&j:um)//查找出现次数最多的字符
                if(j.second>um[MAX])
                    MAX=j.first;
            putchar(MAX);//输出出现次数最多的字符
            error+=m-um[MAX];//加上Hamming距离
            um.clear();//清空map
        }
        printf("\n%d\n",error);//输出Hamming距离和
    }
    return 0;
}
