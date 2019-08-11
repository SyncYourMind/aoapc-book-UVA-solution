#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,ans[10];
    while(cin>>a>>b&&a!=0){
        memset(ans,0,sizeof(ans));
        if(a<b)//让a位大数，b位小数
            swap(a,b);
        int left1=a/10,left2=b/10,cur1=a%10,cur2=b%10,right1=0,right2=0,p=1;//p为10的次幂
        while(!(left1==0&&cur1==0)){//大数a所有位遍历完成，就可以跳出循环
            for(int digit=0;digit<10;++digit){
                ans[digit]+=(left1-left2-1)*p;
                if(cur1>digit)
                    ans[digit]+=p;
                else if(cur1==digit)
                    ans[digit]+=(p==1)?1:(right1+1);
                if(digit==0&&cur2==0&&left2==0)//求0出现的次数要略过下面的操作
                    continue;
                if(cur2<digit)
                    ans[digit]+=p;
                else if(cur2==digit)
                    ans[digit]+=(p==1)?1:(p-right2);
            }
            right1=cur1*p+right1;
            right2=cur2*p+right2;
            cur1=left1%10;
            cur2=left2%10;
            left1/=10;
            left2/=10;
            p*=10;
        }
        for(int i=0;i<10;++i)
            printf("%s%d",i>0?" ":"",ans[i]);
        puts("");
    }
    return 0;
}
