#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    map<string,int>m;//存储输入字符串转换为小写字母并排序后的字符串及其出现次数
    set<string>store;//存储输入的字符串
    while(cin>>s&&s!="#"){
        store.insert(s);//将字符串s插入到store中
        for(char&c:s)//将s中字符均转化为小写
            c=tolower(c);
        sort(s.begin(),s.end());//将字符从小到大排序
        ++m[s];//递增对应的字符串出现次数
    }
    for(auto&i:store){//遍历store中的字符串
        s=i;//s是store中的字符串的一个副本
        for(char&c:s)//将s中字符均转化为小写
            c=tolower(c);
        sort(s.begin(),s.end());//将字符从小到大排序
        if(m[s]==1)//对应的字符串出现次数为1
            puts(i.c_str());//进行输出
    }
    return 0;
}
