#include <stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("%.2f\n",95.0*n>300.0?95.0*n*0.85:95.0*n);
    return 0;
}
