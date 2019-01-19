#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    scanf("%d%*c",&n);//%*c用来吸收换行符
    map<char,pair<int,int>>matrix;//存储矩阵及其行列维度
    for(int i=0;i<n;++i){
        char c;
        scanf("%c%d%d%*c",&c,&a,&b);
        matrix[c]={a,b};
    }
    string line;
    while(getline(cin,line)){
        int ans=0;//乘法次数
        stack<pair<int,int>>s;//栈，元素表示行列维度
        for(char c:line){//遍历一行字符串
            if(c==')'){//遇到右括号
                auto t2=s.top();//存储栈顶元素
                s.pop();//矩阵出栈
                auto t1=s.top();//存储栈顶元素
                s.pop();//矩阵出栈
                if(t1.second!=t2.first){//不能进行乘法运算
                    puts("error");//输出error
                    goto loop;//跳出循环
                }
                ans+=t1.first*t1.second*t2.second;//更新乘法次数
                s.push({t1.first,t2.second});//将乘积矩阵入栈
            }else if(c!='(')//左括号不入栈
                s.push(matrix[c]);
        }
        printf("%d\n",ans);//输出
        loop:;
    }
    return 0;
}
