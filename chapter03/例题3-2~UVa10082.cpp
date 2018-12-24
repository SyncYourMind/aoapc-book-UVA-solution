​#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
    char c;
    while(~scanf("%c",&c))
        if(!isgraph(c))//isgraph(c)函数当c不是空格但是可打印字符时为真
            printf("%c",c);
        else
            printf("%c",s[s.find(c)-1]);//s.find(c)返回字符串s中字符c第一次出现的下标
    return 0;
}
