#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        unordered_map<char,int>m1,m2;
        unordered_map<int,int>k;
        for(char c:s1)
            ++m1[c];
        for(char c:s2)
            ++m2[c];
        for(auto&i:m1)
            ++k[i.second];
        for(auto&i:m2)
            --k[i.second];
        bool f=true;
        for(auto&i:k)
            if(i.second!=0)
                f=false;
        printf("%s\n",f?"YES":"NO");
    }
    return 0;
}
