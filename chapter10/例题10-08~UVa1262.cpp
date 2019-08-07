#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,K;
    scanf("%d",&T);
    while(T--){
        scanf("%d%*c",&K);
        string line,ans="";
        array<unordered_set<char>,5>temp;//存储第一个矩阵每一列的字符
        array<vector<char>,5>letters;//存储两个矩阵每列都有的字符
        int conditions[5]={1,1,1,1,1};//conditions[i]表示i位以后的字符组合的情况数
        for(int i=0;i<6;++i){
            getline(cin,line);
            for(int j=0;j<line.size();++j)
                temp[j].insert(line[j]);
        }
        for(int i=0;i<6;++i){
            getline(cin,line);
            for(int j=0;j<line.size();++j)
                if(temp[j].find(line[j])!=temp[j].end()&&find(letters[j].begin(),letters[j].end(),line[j])==letters[j].end())
                    letters[j].push_back(line[j]);
        }
        for(auto&i:letters)//排序
            sort(i.begin(),i.end());
        for(int i=3;i>=0;--i)
            conditions[i]=conditions[i+1]*letters[i+1].size();
        --K;
        for(int i=0;i<5;++i){
            if(conditions[i]==0||K/conditions[i]>=letters[i].size()){
                ans="NO";
                break;
            }
            ans+=letters[i][K/conditions[i]];
            K%=conditions[i];
        }
        puts(ans.c_str());
    }
    return 0;
}
