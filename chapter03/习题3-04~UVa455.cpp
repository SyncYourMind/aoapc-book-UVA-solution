#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    string s;
    while(N--){
        cin>>s;
        int i=1;//周期
        for(;i<=s.size();++i){//枚举从1到s.size()之间所有的数作为周期
            if(s.size()%i==0){//周期必然可以被s.size()整除
                for(int k=i;k<s.size();++k)//枚举第一个周期以外的所有字符
                    if(s[k]!=s[k%i])//如果和第一个周期内的对应字符不同
                        goto loop;//进行跳转
                break;//找到了一个符合要求的周期，跳出循环
                loop:;//验证下一个周期
            }
        }
        printf("%d\n%s",i,N>0?"\n":"");//输出
    }
    return 0;
}
