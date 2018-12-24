#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s1,s2;
    while(cin>>n&&n!=-1){
        cin>>s1>>s2;
        unordered_set<char>set1,set2;
        for(char c:s1)//把字符串s1中所有字符扔到set1中去重
            set1.insert(c);
        int num=0;//记录猜错次数
        for(char c:s2){//遍历字符串s2
            if(set1.find(c)!=set1.end()&&set2.find(c)==set2.end()){
                set2.insert(c);
                if(set1.size()==set2.size())
                    break;
            }else if(++num==7)//猜错次数达到七次
                    break;
        }
        printf("Round %d\nYou %s.\n",n,num==7?"lose":set1.size()==set2.size()?"win":"chickened out");
    }
    return 0;
}
