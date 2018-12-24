#include <stdio.h>
int main(){
    int count=1,a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c)){
        int i;
        for(i=10;i<=100;++i)
            if(i%3==a&&i%5==b&&i%7==c)
                break;
        if(i==101)
            printf("No answer\n");
        else
            printf("Case %d: %d\n",count,i);
 
    }
    return 0;
}
