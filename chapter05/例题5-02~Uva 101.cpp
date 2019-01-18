#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>blocks(25);
void findBlock(int id,int&p,int&h){//确定编号为id的木块的位置
    for(p=0;p<blocks.size();++p)
        for(h=0;h<blocks[p].size();++h)
            if(blocks[p][h]==id)
                return;
}
void reset(int p,int h){//将第p个木快堆高度h以上的木块复归原位
    for(int i=h+1;i<blocks[p].size();++i)
        blocks[blocks[p][i]].push_back(blocks[p][i]);
    blocks[p].resize(h+1);
}
void pile(int pa,int pb,int ha){//将第pa个木块高度ha以上的木块摞在第pb个木块堆的顶部
    for(int i=ha;i<blocks[pa].size();++i)
        blocks[pb].push_back(blocks[pa][i]);
    blocks[pa].resize(ha);
}
int main(){
    int N,a,b;
    cin>>N;
    string s1,s2;
    for(int i=0;i<N;++i)//初始化每个木块堆
        blocks[i].push_back(i);
    while(cin>>s1>>a>>s2>>b){
        int pa,pb,ha,hb;
        findBlock(a,pa,ha);//搜索编号为a的木块的位置
        findBlock(b,pb,hb);//搜索编号为b的木块的位置
        if(pa==pb)//如果位于同一个木块堆
            continue;//略去以下步骤
        if(s1=="move"){
            if(s2=="onto")
                reset(pb,hb);//把b上方的木块全部归位
            reset(pa,ha);//把a上方的木块全部归位
            blocks[pb].push_back(a);//把a摞在b上面
            blocks[pa].pop_back();
        }else if(s1=="pile"){
            if(s2=="onto")
                reset(pb,hb);//把b上方的木块全部归位
            pile(pa,pb,ha);//把a及上面的木块整体摞在b所在木块堆的顶部
        }
    }
    for(int i=0;i<N;++i){//输出
        printf("%d:",i);
        for(auto j:blocks[i])
            printf(" %d",j);
        puts("");
    }
    return 0;
}
