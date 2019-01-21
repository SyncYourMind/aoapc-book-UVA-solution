#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data,left,right,pathValue;//数据域
    Node(int d):data(d),left(-1),right(-1),pathValue(d){}
};
vector<Node> inOrder;
vector<int> postOrder;
int ans=0,MINpath=INT_MAX;
int createTree(int left,int right,int root,int index){//根据中序序列、后序序列重建树
    if(left>right)
        return -1;
    int i=left;
    while(inOrder[i].data!=postOrder[root])//查找根在中根序列中的位置
        ++i;
    //更新从根结点到该结点的路径权值
    inOrder[i].pathValue+=(index!=-1)?inOrder[index].pathValue:0;
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
    string line,word;
    while(getline(cin,line)){
        inOrder.clear();
        postOrder.clear();
        stringstream out(line);
        while(out>>word)//读取中根序列
            inOrder.push_back(Node(stoi(word)));
        getline(cin,line);
        out=stringstream(line);
        while(out>>word)//读取后根序列
            postOrder.push_back(stoi(word));
        MINpath=INT_MAX;
        createTree(0,postOrder.size()-1,postOrder.size()-1,-1);
        printf("%d\n",inOrder[ans].data);
    }
    return 0;
}
