#include<bits/stdc++.h>
using namespace std;
int C,S,Q,graph[105][105];
const int INF=0x3fffffff;
int main(){
    for(int ii=1;scanf("%d%d%d",&C,&S,&Q)&&C!=0;++ii){
        printf("%sCase #%d\n",ii>1?"\n":"",ii);
        for(int i=0;i<C+1;++i)
            for(int j=0;j<C+1;++j)
                graph[i][j]=INF;
        int a,b,c;
        while(S--){
            scanf("%d%d%d",&a,&b,&c);
            graph[a][b]=graph[b][a]=c;
        }
        for(int k=1;k<C+1;++k)
            for(int i=1;i<C+1;++i)
                for(int j=1;j<C+1;++j)
                    graph[i][j]=min(graph[i][j],max(graph[i][k],graph[k][j]));
        while(Q--){
            scanf("%d%d",&a,&b);
            if(graph[a][b]==INF)
                puts("no path");
            else
                printf("%d\n",graph[a][b]);
        }
    }
    return 0;
}
