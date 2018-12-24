#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,Q,a;
    for(int ii=1;~scanf("%d%d",&N,&Q)&&!(N==0&&Q==0);++ii){
        printf("CASE# %d:\n",ii);
        int A[N];
        for(int i=0;i<N;++i)
            scanf("%d",&A[i]);
        sort(A,A+N);//从小到大排序
        while(Q--){
            scanf("%d",&a);
            auto i=find(A,A+N,a)-A;//在容器A中查找a的位置
            if(i==N)
                printf("%d not found\n",a);
            else
                printf("%d found at %d\n",a,i+1);
        }
    }
    return 0;
}
