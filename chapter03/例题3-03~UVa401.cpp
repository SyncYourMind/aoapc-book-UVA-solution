#include<bits/stdc++.h>
using namespace std;
const string mirrorString ="A   3  HIL JM O   2TUVWXY51SE Z  8 ";//储存每个字符的镜像字符
bool isRegularPalindrome(const string&s){//判断是否是回文字符串
    for(int i=0,j=s.size()-1;i<j;++i,--j)//从字符串两端向中间比较字符
        if(s[i]!=s[j])
            return false;
    return true;
}
bool isMirrorString(const string&s){//判断是否是镜像字符串
    string ss="";//储存字符串s的镜像字符串
    for(char c:s)
        ss+=mirrorString[isdigit(c)?c-'0'+25:c-'A'];
    reverse(ss.begin(),ss.end());//翻转ss字符串
    return s==ss;//s如果与ss相同则是镜像字符串，否则不是
}
int main(){
    string s;
    while(getline(cin,s)){
        bool f1=isRegularPalindrome(s),f2=isMirrorString(s);
        if(!f1&&!f2)
            cout<<s<<" -- is not a palindrome."<<endl<<endl;
        else if(f1&&!f2)
            cout<<s<<" -- is a regular palindrome."<<endl<<endl;
        else if(!f1&&f2)
            cout<<s<<" -- is a mirrored string."<<endl<<endl;
        else
            cout<<s<<" -- is a mirrored palindrome."<<endl<<endl;
    }
    return 0;
}
