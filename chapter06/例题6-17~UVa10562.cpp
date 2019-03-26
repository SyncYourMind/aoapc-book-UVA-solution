#include<bits/stdc++.h>
using namespace std;
pair<int,int>find_range(int i,int j,vector<string>&tree){//查找连续-字符的首末位置
    int start=j,last=j;
    while(start>=0&&tree[i][start]=='-')
        --start;
    while(last<tree[i].size()&&tree[i][last]=='-')
        ++last;
    return {start+1,last-1};
}
void DFS(int i,int j,vector<string>&tree){//递归输出
    printf("%c(",tree[i][j]);
    if(i+1<tree.size()&&j<tree[i].size()&&tree[i+1][j]=='|'){
        pair<int,int>p=find_range(i+2,j,tree);
        for(int k=p.first;k<tree[i+3].size()&&k<=p.second;++k)
            if(tree[i+3][k]!=' '&&tree[i+3][k]!='#')
                DFS(i+3,k,tree);
    }
    printf(")");
}
int main(){
    int T;
    scanf("%d%*c",&T);
    while(T--){
        vector<string>tree;
        string line;
        while(getline(cin,line)&&line!="#")
            tree.push_back(line);
        printf("(");
        if(!tree.empty()){
            int i=tree[0].size()-1;
            DFS(0,i,tree);
        }
        puts(")");
    }
    return 0;
}
