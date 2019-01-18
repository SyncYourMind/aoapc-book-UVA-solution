#include<bits/stdc++.h>
using namespace std;
vector<set<int>>sets;//存储集合
map<set<int>,int>idCache;//集合与sets下标的映射关系
int ID(set<int>&s){//获取集合在sets中的下标
    if(idCache.find(s)==idCache.end()){//没有这一集合，分配一个新的id
        idCache[s]=sets.size();
        sets.push_back(s);
    }
    return idCache[s];
}
int main(){
    int T,N;
    cin>>T;
    while(T--){
        cin>>N;
        stack<int>s;
        string input;
        while(N--){
            cin>>input;
            if(input=="PUSH"){
                set<int>temp;
                s.push(ID(temp));
            }else if(input=="DUP"){
                s.push(ID(sets[s.top()]));
            }else{
                int id1=s.top();
                s.pop();
                int id2=s.top();
                s.pop();
                set<int>result;
                if(input=="UNION"){
                    set_union(sets[id1].begin(),sets[id1].end(),sets[id2].begin(),sets[id2].end(),inserter(result,result.begin()));
                }else if(input=="INTERSECT"){
                    set_intersection(sets[id1].begin(),sets[id1].end(),sets[id2].begin(),sets[id2].end(),inserter(result,result.begin()));
                }else if(input=="ADD"){
                    result=sets[id2];
                    result.insert(ID(sets[id1]));
                }
                s.push(ID(result));
            }
            cout<<sets[s.top()].size()<<endl;
        }
        cout<<"***"<<endl;
    }
    return 0;
}
