#include<bits/stdc++.h>
using namespace std;
char oil[105][105];
bool visit[105][105];
int m,n;
void DFS(int i,int j){
    visit[i][j]=true;
    if(oil[i][j]=='@')
        for(int ii=i-1;ii<=i+1;++ii)
            for(int jj=j-1;jj<=j+1;++jj)
                if(i>=0&&i<m&&j>=0&&j<n&&!visit[ii][jj]&&oil[ii][jj]=='@')
                    DFS(ii,jj);
}
int main(){
    while(~scanf("%d%d%*c",&m,&n)&&m!=0){
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                scanf("%c",&oil[i][j]);
                visit[i][j]=false;
            }
            getchar();
        }
        int num=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(!visit[i][j]&&oil[i][j]=='@'){
                    ++num;
                    DFS(i,j);
                }
        printf("%d\n",num);
    }
    return 0;
}
