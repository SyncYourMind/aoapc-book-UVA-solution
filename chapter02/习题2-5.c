#include <stdio.h>
int main(){
    int a,b,c,count=1;
    while(~scanf("%d%d%d",&a,&b,&c)&&!(a==0&&b==0&&c==0))
        printf("Case %d: %.*f\n",count++,c,a*1.0/b);
    return 0;
}
