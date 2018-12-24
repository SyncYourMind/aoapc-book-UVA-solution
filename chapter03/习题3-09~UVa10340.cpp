#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    while(cin>>s>>t){
        int i=0;
        for(char c:t)
            if(c==s[i])
                ++i;
        if(i==s.size())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
