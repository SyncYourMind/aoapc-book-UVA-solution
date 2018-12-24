#include<bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);++i) //循环的简单宏表示
int main(){
    const double log10_2=log10(2.0),limit=1e-6;
    vector<double>epow={0.0},mpow={0.5};//打表用的vector
    _for(i,0,30)//计算2^E-1
        epow.push_back(2.0*epow.back()+1.0);
    _for(i,0,10)//计算2^(1/(M+1))
        mpow.push_back(mpow.back()/2.0);
    for(auto&i:mpow)//计算lg(1−2^(1/(M+1)))
        i=log10(1.0-i);
    for(auto&i:epow)//计算(2^E-1)∗lg2
        i*=log10_2;
    double A;
    int B,M,E;
    char input[20];
    while(~scanf("%s",input)&&strcmp(input,"0e0")!=0){//进行输入
        *strchr(input,'e')=' ';//将字符串中的字符e替换为空格
        sscanf(input,"%lf%d",&A,&B);//在字符串中读取A和B
        A=B*1.0+log10(A);//求出等式右端的值
        _for(E,1,epow.size())//开始遍历查找答案
            _for(M,0,mpow.size())
                if(fabs(mpow[M]+epow[E]-A)<=limit){//差的绝对值小于10^(-6)时，即可认为两者相等
                    printf("%d %d\n",M,E);
                    break;
                }
    }
    return 0;
}
