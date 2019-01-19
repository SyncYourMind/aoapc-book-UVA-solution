#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    for(int ii=0;~scanf("%d",&n)&&n!=0;++ii){
        int exit[n];
        while(~scanf("%d",&exit[0])&&exit[0]!=0){
            for(int i=1;i<n;++i)
                scanf("%d",&exit[i]);
            stack<int>s;//栈
            bool yes=true;//标志能否产生相应的出栈次序
            int MAX=0;//出栈的最大元素
            for(int i=0;i<n;++i)//遍历出栈次序
                if(s.empty()||s.top()<exit[i]){//栈空或者当前出栈元素比栈顶元素大
                    for(int j=MAX+1;j<exit[i];++j)//把[最大出栈元素,当前出栈元素)之间的数入栈
                        s.push(j);
                    MAX=max(exit[i],MAX);//更新最大出栈元素
                }else if(s.top()==exit[i]){//栈顶元素和当前出栈元素相同
                    s.pop();//出栈
                    MAX=max(exit[i],MAX);//更新最大出栈元素
                }else{//当前出栈元素比栈顶元素小，则不能产生相应出栈元素
                    yes=false;
                    break;
                }
            puts(yes?"Yes":"No");
        }
        puts("");
    }
    return 0;
}
