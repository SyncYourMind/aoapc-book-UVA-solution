#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,N,A[10];
    scanf("%d",&T);
    while(T--){
        memset(A,0,sizeof(A));//将A数组所有元素初始化为0
        for(scanf("%d",&N);N>0;--N)//枚举N~1这N个数字
            for(int k=N;k>0;k/=10)
                ++A[k%10];
        for(int i=0;i<10;++i)
            printf("%d%s",A[i],i<9?" ":"");//每行末尾不能有空格
        printf("\n");
    }
    return 0;
}
