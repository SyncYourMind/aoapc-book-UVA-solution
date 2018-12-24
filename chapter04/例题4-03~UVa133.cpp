#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,m;
    while(~scanf("%d%d%d",&n,&k,&m)&&!(n==0&&k==0&&m==0)){
        bool A[n]={false};
        int i=0,j=n-1,order=0;//order是为了决定是否输出逗号
        while(find(A,A+n,false)!=A+n){//数组中找不到为false的元素时跳出循环
            for(int num=0;true;i=(i+1)%n)//i递增逆时针数k个没有被选中的人
                if(!A[i]&&++num==k)
                    break;
            for(int num=0;true;j=(n+j-1)%n)//j递减顺时针数m个没有被选中的人
                if(!A[j]&&++num==m)
                    break;
            printf("%s%3d",order++==0?"":",",i+1);
            if(j!=i)
                printf("%3d",j+1);
            A[i]=A[j]=true;
        }
        puts("");
    }
    return 0;
}
