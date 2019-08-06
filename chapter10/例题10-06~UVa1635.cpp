#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>MF;//m的唯一分解式
void getFactor(int n){//求出数字m的唯一分解式
    for(int i=2;i<=(int)sqrt(n*1.0);++i){
        int j=0;
        for(;n%i==0;n/=i)
            ++j;
        if(j!=0)
            MF[i]+=j;
        if(n==1)
            break;
    }
    if(n>1)
        ++MF[n];
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        vector<bool>temp(n,true);//标志系数是否能被m整除
        temp.front()=temp.back()=false;//首尾系数肯定不能被m整除
        MF.clear();
        getFactor(m);
        for(auto&i:MF){
            int num=0;//表示当前系数对于i.first的指数
            for(int j=1;j<n-1;++j){
                int x=n-j;
                for(;x%i.first==0;x/=i.first)
                    ++num;
                x=j;
                for(;x%i.first==0;x/=i.first)
                    --num;
                if(num<i.second)//当前系数对于i.first的指数比i.second小，则当前系数不能整除m
                    temp[j]=false;
            }
        }
        vector<int>ans;
        for(int i=0;i<temp.size();++i)//将能被m整除的项的序号放进ans中
            if(temp[i])
                ans.push_back(i+1);//题目是从1开始编号的
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();++i)
            printf("%d%s",ans[i],i==ans.size()-1?"":" ");
        puts("");
    }
    return 0;
}
