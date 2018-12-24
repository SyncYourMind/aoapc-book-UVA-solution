#include <stdio.h>
#include<math.h>
int main(){
    int n;
    double pi=acos(-1.0);
    scanf("%d",&n);
    printf("%f %f\n",sin(n/180.0*pi),cos(n/180.0*pi));
    return 0;
}
