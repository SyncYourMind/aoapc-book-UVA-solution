#include<bits/stdc++.h>
using namespace std;
//image1和image2分别代表两个图像字符串，i1和i2分别代表当前遍历到的两个字符串的字符索引
//pixels代表该层一个f结点代表的黑色像素个数，ans代表最终结果
void DFS(string&image1,int&i1,string&image2,int&i2,int pixels,int&ans){
    if(image1[i1]!='p'&&image2[i2]!='p'){//两个不是父节点
        ans+=(image1[i1]=='f'||image2[i2]=='f')?pixels:0;//有一个是'f'结点，就进行累加
    }else if(image1[i1]=='p'&&image2[i2]=='p'){//两个都是父节点
        for(int i=1;i<=4;++i)//同时遍历其4个子节点
            DFS(image1,++i1,image2,++i2,pixels/4,ans);
    }else if(image1[i1]=='p')//image1处是父节点
        for(int i=0;i<4;++i)//遍历image1的4个子节点
            DFS(image1,++i1,image2,i2,pixels/4,ans);
    else//image2处是父节点
        for(int i=0;i<4;++i)//遍历image2的4个子节点
            DFS(image1,i1,image2,++i2,pixels/4,ans);

}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        string line1,line2;
        cin>>line1>>line2;
        int ans=0,i1=0,i2=0;
        DFS(line1,i1,line2,i2,1024,ans);
        printf("There are %d black pixels.\n",ans);
    }
    return 0;
}
