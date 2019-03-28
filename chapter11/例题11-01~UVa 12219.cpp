#include<bits/stdc++.h>
using namespace std;
struct Node{
    string data;
    int left,right;
    Node(string d="",int l=-1,int r=-1):data(d),left(l),right(r){}
};
string line;
Node tree[50005];//存储整棵树
int output[50005];//结点是否输出过
int createTree(int&index,int&num,unordered_map<string,int>&trans){//先序遍历建树
    int id=num++,i=index;//id表示当前子树的编号，num表示下一棵子树的编号
    while(index<line.size()&&isalpha(line[index]))//查找最近的非字母字符的位置
        ++index;
    tree[id]=Node(line.substr(i,index-i));//截取根结点的名字
    if(index<line.size()&&line[index]=='('){//如果接下来是(，表示有两个孩子
        tree[id].left=createTree(++index,num,trans);//递归遍历左子树
        tree[id].right=createTree(++index,num,trans);//递归遍历右子树
        ++index;
    }
    string s=tree[id].data+"("+to_string(tree[id].left)+","+to_string(tree[id].right)+")";//唯一标识一棵子树
    if(trans.find(s)==trans.end()){//该子树没有出现过
        trans.insert({s,id});//在map中插入该子树
    }else//子树出现过
        --num;//递减当前下一棵子树的编号
    return trans[s];
}
void DFS(int root,int x){//递归遍历输出
    if(output[root]==x){//该子树已经输出过
        printf("%d",root);//输出子树编号
        return;
    }
    output[root]=x;//置当前子树为已输出过
    printf("%s",(tree[root].data).c_str());
    if(tree[root].left==-1)
        return;
    printf("(");
    DFS(tree[root].left,x);
    printf(",");
    DFS(tree[root].right,x);
    printf(")");
}
int main() {
    int c;
    scanf("%d%*c",&c);
    for(int i=1;getline(cin,line);++i){
        unordered_map<string,int>trans;
        int index=0,num=1;
        DFS(createTree(index,num,trans),i);
        puts("");
    }
    return 0;
}
