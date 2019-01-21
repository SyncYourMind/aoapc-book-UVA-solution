#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;//数据域
    Node*left,*right;//左右孩子指针
    Node(int d,int p):data(d),left(nullptr),right(nullptr){}
};
map<int,int>ans;
//返回false代表空树，参数p代表当前结点水平位置，参数root代表当前结点是不是根结点
bool DFS(int p,bool root){
    int data;
    scanf("%d",&data);
    if(data==-1)//读取到的数据为-1
        if(root)//如果当前结点是根结点
            return false;//树为空树，返回false
        else//不是根结点
            return true;//树不是空树，返回true
    if(root)//是根结点
        ans.clear();//清空map
    ans[p]+=data;//在对应水平位置加上结点权值
    DFS(p-1,false);//递归遍历左子树
    DFS(p+1,false);//递归遍历右子树
    return true;//返回true,代表不是空树
}
int main(){
    while(true){
        for(int i=1;DFS(0,true);++i){
            printf("Case %d:\n",i);
            for(auto j=ans.begin();j!=ans.end();++j)
                printf("%s%d",j==ans.begin()?"":" ",j->second);
            printf("\n\n");
        }
        break;
    }
    return 0;
}
