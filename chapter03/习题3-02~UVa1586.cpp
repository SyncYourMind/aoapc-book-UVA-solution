#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    string s;
    scanf("%d",&T);
    unordered_map<char,double>m={//存储原子和对应的原子质量
        {'C',12.01},{'H',1.008},{'O',16.00},{'N',14.01}
    };
    while(T--){
        cin>>s;
        double result=0.0;
        for(int i=0;i<s.size();){
            int j=i+1;//变量j用来寻找字符s[i]后的第一个字母的位置
            while(j<s.size()&&isdigit(s[j]))++j;
            if(j==i+1)//i,j之间没有数字
                result+=m[s[i]];//加一份原子质量
            else//i,j之间有数字
                result+=m[s[i]]*stoi(s.substr(i+1,j-i));
            i=j;
        }
        printf("%.3f\n",result);
    }
    return 0;
}
