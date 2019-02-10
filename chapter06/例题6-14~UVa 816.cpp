#include<bits/stdc++.h>
using namespace std;
struct Node{//结点类
    int r,c,d;//行、列、方向
    Node(int row=0,int col=0,int direc=0):r(row),c(col),d(direc){}
};
int direction[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//NESW方向
unordered_map<char,int>trans={{'N',0},{'E',1},{'S',2},{'W',3},{'L',-1},{'R',1},{'F',0}};//字符与方向的映射
Node start,dest,past[10][10][4];//起点、终点、每个结点在最短路径中的父节点
vector<int>point[10][10][4];//每个结点处的路标及朝向
bool BFS(Node p){//广度优先搜索求最短路
    queue<Node>q;
    q.push(p);//入队
    bool inQueue[10][10][4]={false};//某结点是否已经进入队列
    inQueue[p.r][p.c][p.d]=true;//该结点已进入队列
    past[p.r][p.c][p.d]=start;//置父节点
    while(!q.empty()){//队列不空
        p=q.front();//出队
        q.pop();
        if(p.r==dest.r&&p.c==dest.c){//到达终点
            dest.d=p.d;//补充终点的朝向
            return true;//找到了最短路，返回true
        }
        if(p.r>0&&p.r<10&&p.c>0&&p.c<10&&!point[p.r][p.c][p.d].empty()){//观察该结点是否有该朝向的路标
            for(int i:point[p.r][p.c][p.d]){//遍历该路标下的转向
                int d=(p.d+i+4)%4,ii=p.r+direction[d][0],jj=p.c+direction[d][1];//求转向之后下一个节点
                if(ii>0&&ii<10&&jj>0&&jj<10&&!inQueue[ii][jj][d]){//下一个节点尚未入队
                    q.push(Node(ii,jj,d));//入队
                    inQueue[ii][jj][d]=true;//该结点已进入队列
                    past[ii][jj][d]=p;//置父节点
                }
            }
        }
    }
    return false;//找不到最短路，返回false
}
void DFS(Node v,vector<Node>&path){//深度优先搜索打印最短路径
    if(v.r==start.r&&v.c==start.c&&v.d==start.d){//到达了起点
        path.push_back(v);
        for(int i=0;i<path.size();++i)//打印
            printf("%s (%d,%d)",i%10==0?"\n ":"",path[path.size()-1-i].r,path[path.size()-1-i].c);
        puts("");
        return;
    }
    path.push_back(v);
    DFS(past[v.r][v.c][v.d],path);//深度优先搜索父节点
}
int main(){
    string s;
    while(getline(cin,s)&&s!="END"){
        for(int i=0;i<10;++i)
            for(int j=0;j<10;++j)
                for(int k=0;k<4;++k){
                    past[i][j][k]=Node();
                    point[i][j][k].clear();
                }
        printf("%s",s.c_str());
        cin>>start.r>>start.c>>s>>dest.r>>dest.c;
        start.d=-1;//到达起点时的朝向置为-1
        int a,b,d=trans[s[0]];
        while(scanf("%d%*c",&a)&&a!=0){
            scanf("%d",&b);
            while(cin>>s&&s!="*"){
                for(int j=1;j<s.size();++j)
                    point[a][b][trans[s[0]]].push_back(trans[s[j]]);
            }
        }
        if(BFS(Node(start.r+direction[d][0],start.c+direction[d][1],d))){//直接从起点的下一个节点开始搜索
            vector<Node>path;
            DFS(dest,path);
        }else
            puts("\n  No Solution Possible");
    }
    return 0;
}
