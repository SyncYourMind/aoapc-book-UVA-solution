#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data=0,left=-1,right=-1,pathValue=0;//数据域
};
Node inOrder[10005];
int postOrder[10005];
int ans=0,MINpath=INT_MAX;
int split(string&s,bool in){//分割字符串
    int size=0;
    string t="";
    for(int i=0;i<=s.size();++i)
        if(i==s.size()||s[i]==' '){
            if(in){
                inOrder[size].left=inOrder[size].right=-1;
                inOrder[size++].data=stoi(t);
            }else
                postOrder[size++]=stoi(t);
            t="";
        }else
            t+=s[i];
    return size;
}
int createTree(int left,int right,int root,int index){//根据中序序列、后序序列重建树
    if(left>right)
        return -1;
    int i=left;
    while(inOrder[i].data!=postOrder[root])//查找根在中根序列中的位置
        ++i;
    //更新从根结点到该结点的路径权值
    inOrder[i].pathValue=(index!=-1)?inOrder[index].pathValue+inOrder[i].data:inOrder[i].data;
    inOrder[i].left=createTree(left,i-1,root-1+i-right,i);//递归重建左子树
    inOrder[i].right=createTree(i+1,right,root-1,i);//递归重建右子树
    if(inOrder[i].left==-1&&inOrder[i].right==-1//是叶结点
        &&(inOrder[i].pathValue<MINpath//从根结点到该结点的路径权值小于当前最大路径权值
           ||(inOrder[i].pathValue==MINpath&&inOrder[i].data<inOrder[ans].data))){
            ans=i;//更新最小路径权值的叶子结点
            MINpath=inOrder[i].pathValue;//更新最小路径权值
        }
    return i;
}
int main(){
    string line;
    while(getline(cin,line)){
        int n=split(line,true);
        getline(cin,line);
        n=split(line,false);
        MINpath=INT_MAX;
        createTree(0,n-1,n-1,-1);
        printf("%d\n",inOrder[ans].data);
    }
    return 0;
}
