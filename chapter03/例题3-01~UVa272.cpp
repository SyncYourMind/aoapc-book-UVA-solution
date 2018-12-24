#include<bits/stdc++.h>
using namespace std;
int main(){
    bool flag=false;
    char c;
    while(~scanf("%c",&c))
        if(c=='\"'){
            printf("%s",flag?"\'\'":"``");
            flag=!flag;
        }else
            printf("%c",c);
    return 0;
}
