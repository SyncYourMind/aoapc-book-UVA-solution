#include<bits/stdc++.h>
using namespace std;
struct Node{
    bool value=false;//标志该结点是否已被赋值
    int data;//数据域
    Node*left=nullptr,*right=nullptr;//左右孩子指针
};
bool f=true;//标志一个结点是否被重复赋值
void insert(int data,string s,Node*root){//插入结点
    for(auto c:s)//遍历标志结点位置的字符串
        if(c=='L'){//如果是L字符，向左子树插入
            if(root->left==nullptr)
                root->left=new Node();
            root=root->left;
        }else{//如果是R字符，向右子树插入
            if(root->right==nullptr)
                root->right=new Node();
            root=root->right;
        }
    if(root->value)//当前结点已被赋值
        f=false;//该结点被重复赋值
    root->data=data;//更新该结点数据域
    root->value=true;//该结点已被赋值
}
bool levelOrder(Node*root,vector<int>&level){//层次遍历
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        root=q.front();
        q.pop();
        if(!root->value)//该结点没有被赋值，返回false
            return false;
        level.push_back(root->data);
        if(root->left!=nullptr)
            q.push(root->left);
        if(root->right!=nullptr)
            q.push(root->right);
    }
    return true;
}
int main(){
    string input;
    Node*root=new Node();
    while(cin>>input){
        if(input=="()"){//是空括号，一棵树已输入完成
            vector<int>level;//存储层次遍历序列
            if(f&&levelOrder(root,level)){
                for(int i=0;i<level.size();++i)
                    printf("%s%d",i>0?" ":"",level[i]);
                puts("");
            }else
                puts("not complete");
            root=new Node();
            f=true;
        }else{
            int i=input.find(',');
            insert(stoi(input.substr(1,i-1)),input.substr(i+1,input.size()-2-i),root);
        }
    }
    return 0;
}
