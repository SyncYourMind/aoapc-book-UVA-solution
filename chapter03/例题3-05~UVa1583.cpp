#include<bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);++i)//for循环的一种用宏表示的简写方式
int A[100100];
int main(){
    _for(i,0,100000){
        string s=to_string(i);
        int k=i;
        _for(j,0,s.size()) k+=s[j]-'0';
        if(A[k]==0)
            A[k]=i;
    }
    int N,input;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&input);
        printf("%d\n",A[input]);
    }
    return 0;
}
