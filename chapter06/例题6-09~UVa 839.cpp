#include<bits/stdc++.h>
using namespace std;
struct Node{
    int Wl,Dl,Wr,Dr;//数据域
    Node*left=nullptr,*right=nullptr;//左右孩子指针
};
int DFS(Node*&root,bool&f){//深度优先遍历
    root=new Node();
    scanf("%d%d%d%d",&root->Wl,&root->Dl,&root->Wr,&root->Dr);
    if(root->Wl==0)//Wl是0
        root->Wl=DFS(root->left,f);//递归建立左子天平
    if(root->Wr==0)//Wr是0
        root->Wr=DFS(root->right,f);//递归建立右子天平
    if(root->Dl*root->Wl!=root->Dr*root->Wr)//左右力矩不相等
        f=false;//置f为false
    return root->Wl+root->Wr;//返回整个天平重量
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        Node*root=nullptr;
        bool f=true;
        DFS(root,f);
        printf("%s%s\n",i>0?"\n":"",f?"YES":"NO");
    }
    return 0;
}
