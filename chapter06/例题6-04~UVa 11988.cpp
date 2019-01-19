#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    while(getline(cin,line)){
        list<char>text;
        auto i=text.end();
        for(char c:line)
            if(c=='[')
                i=text.begin();
            else if(c==']')
                i=text.end();
            else{
                i=text.insert(i,c);
                ++i;
            }
        for(char c:text)
            putchar(c);
        puts("");
    }
    return 0;
}
