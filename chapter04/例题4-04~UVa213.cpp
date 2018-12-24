#include<bits/stdc++.h>
using namespace std;
int readchar(int n){
    int k=0;
    while(n--){
        char c=getchar();
        while(c=='\n')
            c=getchar();
        k=k*2+c-'0';
    }
    return k;
}
int main(){
    string s;
    int v1[10]={0},v2[10]={0};
    for(int i=1;i<10;++i)
        v1[i]=2*v1[i-1]+1;
    for(int i=1;i<10;++i)
        v2[i]=v1[i]+v2[i-1];
    while(getline(cin,s)){
        int num=readchar(3);//num即代表接下来将要读取的01串长度
        while(num!=0){//01串不是全0，继续循环
            int t=readchar(num);//t为该01串表示的十进制数
            while(t<v1[num]){//01串是全1时，小节结束，跳出循环
                putchar(s[v2[num-1]+t]);//输出相应字符
                t=readchar(num);//读取下一个有num个字符的01串
            }
            num=readchar(3);
        }
        puts("");//换行
        getchar();//读取后面的换行符
    }
    return 0;
}
