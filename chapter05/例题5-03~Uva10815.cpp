#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    set<string>dic;
    while(cin>>s){
        for(auto&c:s)
            if(!isalpha(c))
                c=' ';
            else
                c=tolower(c);
        stringstream stream(s);
        while(stream>>s)
            dic.insert(s);
    }
    for(string ss:dic)
        puts(ss.c_str());
    return 0;
}
