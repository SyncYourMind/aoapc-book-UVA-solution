#include<bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);++i)//for循环的一种用宏表示的简写方式
bool compare(const string&s,int a,int b){//比较以a、b位置开始的串的字典序大小
    _for(i,0,s.size())
        if(s[(a+i)%s.size()]!=s[(b+i)%s.size()])
            return s[(a+i)%s.size()]<s[(b+i)%s.size()];
    return false;
}
int main(){
    int T;
    string s;
    scanf("%d",&T);
    while(T--){
        int result=0;
        cin>>s;
        _for(i,1,s.size())
            if(compare(s,i,result))
                result=i;
        _for(i,0,s.size()) putchar(s[(i+result)%s.size()]);
        putchar('\n');
    }
    return 0;
}
