#include<bits/stdc++.h>
using namespace std;
vector<string> cards(9,"0000");//储存输入的9堆牌的点数
typedef long long ll;
ll bits[9]={1,10,100,1000,10000,(ll)1e5,(ll)1e6,(ll)1e7,(ll)1e8};
unordered_map<ll,double>dp;
double DP(ll n){//动态规划
    if(dp.find(n)!=dp.end())//当前状态已经计算过了，直接返回对应的值
        return dp[n];
    vector<pair<int,int>>pairs;
    for(int i=0;i<cards.size();++i)//求出所有满足条件的两堆牌的编号集合
        if(!cards[i].empty())
            for(int j=i+1;j<cards.size();++j)
                if(!cards[j].empty()&&cards[i].back()==cards[j].back())
                    pairs.push_back({i,j});
    if(pairs.empty())//没有能够抽出的牌，成功概率为0
        return dp[n]=0.0;
    for(auto&i:pairs){//遍历每一组满足条件的两堆牌的编号
        char c=cards[i.first].back();
        cards[i.first].pop_back();
        cards[i.second].pop_back();
        dp[n]+=1.0/pairs.size()*DP(n-bits[i.first]-bits[i.second]);//状态转移
        cards[i.first].push_back(c);
        cards[i.second].push_back(c);
    }
    return dp[n];
}
int main(){
    while (true) {
        dp.clear();
        dp[0]=1.0;//0为最终状态
        string word;
        for(int i=0;i<9;++i){
            for(int j=0;j<4;++j){
                if(!(cin>>word))
                    return 0;
                cards[i][j]=word[0];//只需记录第一个字符
            }
        }
        printf("%.6f\n",DP(444444444));
    }
    return 0;
}
