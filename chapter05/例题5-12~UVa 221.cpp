#include<bits/stdc++.h>
using namespace std;
struct Building{//建筑物类
    double x,y,w,d,h;
    int id;
};
int main(){
    int n;
    for(int ii=1;~scanf("%d",&n)&&n!=0;++ii){
        if(ii>1)//输出两个测试样例间的空行
            puts("");
        vector<Building>buildings(n);
        vector<double>x;//存储x轴坐标
        for(int i=0;i<n;++i){
            scanf("%lf%lf%lf%lf%lf",&buildings[i].x,&buildings[i].y,&buildings[i].w,&buildings[i].d,&buildings[i].h);
            buildings[i].id=i+1;
            x.push_back(buildings[i].x);
            x.push_back(buildings[i].x+buildings[i].w);
        }
        sort(buildings.begin(),buildings.end(),[](Building&a,Building&b){//排序
            return a.x<b.x||(a.x==b.x&&a.y<b.y);
        });
        sort(x.begin(),x.end());//对x坐标排序
        auto ending=unique(x.begin(),x.end())-x.begin();//第一个重复元素在x数组内的下标
        printf("For map #%d, the visible buildings are numbered as follows:\n",ii);
        bool space=false;//标志是否输出空格
        for(int i=0;i<buildings.size();++i){//遍历每一个建筑物
            for(int j=0;j<ending-1;++j){//遍历所有非重复的x坐标
                double mid=(x[j]+x[j+1])/2;//取区间内某一点
                if(buildings[i].x<=mid&&buildings[i].x+buildings[i].w>=mid){//该点在建筑物内
                    bool visible=true;//标志该建筑物是否可见
                    for(int k=0;k<buildings.size();++k)//遍历所有建筑物
                        if(buildings[k].x<=mid&&buildings[k].x+buildings[k].w>=mid//该点在建筑物内
                                &&buildings[k].y<buildings[i].y&&buildings[k].h>=buildings[i].h){//建筑物被遮盖
                            visible=false;//该建筑物不可见
                            break;
                        }
                    if(visible){//该建筑物可见
                        printf("%s%d",space==true?" ":"",buildings[i].id);//输出建筑物标号
                        space=true;
                        break;
                    }
                }
            }
        }
        puts("");
    }
    return 0;
}
