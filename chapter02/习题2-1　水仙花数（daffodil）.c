#include <stdio.h>
int f(int n){
    return n*n*n;
}
int main(){
    for(int i=100;i<1000;++i)
        if(i==f(i/100)+f(i%100/10)+f(i%10))
            printf("%d\n",i);
    return 0;
}
