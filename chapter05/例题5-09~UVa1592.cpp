#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(~scanf("%d%d%*c",&n,&m)){
        string line;
        vector<unordered_map<string,vector<int>>>columns(m);
        for(int i=0;i<n;++i){
            getline(cin,line);
            string s="";
            for(int j=0,k=0;j<=line.size();++j)//j用来分割字符串，k表示列号
                if(j==line.size()||line[j]==','){//遇到字符串末尾或,表示一个字符串分割完毕
                    columns[k++][s].push_back(i);
                    s="";
                }else
                    s+=line[j];
        }
        map<pair<int,int>,int>rows;
        for(int i=0;i<columns.size();++i)//遍历columns
            for(auto&j:columns[i])//对于columns[i]中的每个元素
                if(j.second.size()>1){//该列中字符串出现次数超过1次，即至少有两行字符串相同
                    for(int k1=0;k1<j.second.size();++k1)//遍历行号
                        for(int k2=k1+1;k2<j.second.size();++k2){//遍历行号
                            pair<int,int>p=make_pair(j.second[k1],j.second[k2]);
                            if(rows.find(p)!=rows.end()){
                                printf("NO\n%d %d\n%d %d\n",p.first+1,p.second+1,rows[p]+1,i+1);
                                goto loop;
                            }else
                                rows.insert({p,i});
                        }
                }
        puts("YES");
        loop:;
    }
    return 0;
}
