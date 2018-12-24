#include<bits/stdc++.h>
using namespace std;
int main(){
    int R,C,N,M,K;
    for(int ii=1;~scanf("%d%d",&R,&C)&&(R!=0&&C!=0);++ii){
        printf("%sSpreadsheet #%d\n",ii>1?"\n":"",ii);//如果不是第一个Spreadsheet，前面要先输出一个空行
        vector<pair<string,vector<int>>>operation;//存储操作信息
        scanf("%d",&N);
        while(N--){
            string s;
            cin>>s;//读取操作字符串
            if(s!="EX")
                scanf("%d",&K);
            else//如果是EX操作，需要读取4个整数
                K=4;
            operation.push_back(make_pair(s,vector<int>()));//operation中插入一个操作
            while(K--){
                scanf("%d",&M);
                operation.back().second.push_back(M);//将操作的行列信息放入operation元素的second成员中
            }
        }
        scanf("%d",&M);
        pair<int,int>query;//表示查询的单元格的行列号
        while(M--){
            scanf("%d%d",&query.first,&query.second);//读取一个要查询的单元格
            printf("Cell data in (%d,%d)",query.first,query.second);//先输出原始位置
            for(auto&p:operation)//遍历需进行的操作
                if(p.first=="EX"){//如果是EX操作
                    pair<int,int>p1={p.second[0],p.second[1]},p2={p.second[2],p.second[3]};
                    if(query==p1)//当前查询的单元格是交换的单元格
                        query=p2;//将当前单元格的行列号变为要交换的单元格的行列号
                    else if(query==p2)//当前查询的单元格是交换的单元格
                        query=p1;//将当前单元格的行列号变为要交换的单元格的行列号
                }else{
                    int row=0,col=0;//分别表示行列号的变动情况
                    for(auto&s:p.second){//遍历需进行的操作
                        if(p.first=="DC"){//如果是DC操作
                            if(query.second>s)//当前列号大于删除的列号
                                --col;//当前列号-1
                            else if(query.second==s)//当前列号就是要删除的列号
                                row=col=-100;//行列号均缩减到负数，表示此单元格不再存在
                        }else if(p.first=="DR"){//如果是DR操作
                            if(query.first>s)//当前行号大于删除的行号
                                --row;//当前行号-1
                            else if(query.first==s)//当前行号就是要删除的行号
                                row=col=-100;//行列号均缩减到负数，表示此单元格不再存在
                        }else if(p.first=="IC"&&query.second>=s)//当前列号大于等于要插入的行号
                            ++col;//当前列号+1
                        else if(p.first=="IR"&&query.first>=s)//当前行号大于等于要插入的行号
                            ++row;//当前行号+1
                    }
                    query.first+=row;//更新当前查询单元格的行号
                    query.second+=col;//更新当前查询单元格的列号
                }
            if(query.first<=0||query.second<=0)//行列号为负
                printf(" GONE\n");//该单元格已不存在
            else
                printf(" moved to (%d,%d)\n",query.first,query.second);
        }
    }
    return 0;
}
