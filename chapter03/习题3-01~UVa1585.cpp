#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    string s;
    scanf("%d",&T);
    while(T--){
        cin>>s;
        int current=0,result=0;
        for(char c:s){
            if(c=='O')
                ++current;
            else
                current=0;
            result+=current;
        }
        printf("%d\n",result);
    }
    return 0;
}
