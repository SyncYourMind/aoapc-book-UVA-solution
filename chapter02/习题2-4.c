#include <stdio.h>
int main(){
    int n,m,count=1;
    while(~scanf("%d%d",&n,&m)&&!(n==0&&m==0)){
        double sum=0.0;
        while(n<=m){
            sum+=1.0/n/n;
            ++n;
        }
        printf("Case %d: %.5f\n",count++,sum);
    }
    return 0;
}
