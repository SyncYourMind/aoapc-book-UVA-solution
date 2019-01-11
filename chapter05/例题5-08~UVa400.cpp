#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    while(cin>>N){
        string input;
        vector<string>files;//存储文件名
        int M=0;//存储最长文件名的字符数
        while(N--){
            cin>>input;
            M=max(M,(int)(input.size()));
            files.push_back(input);
        }
        sort(files.begin(),files.end());//排序
        int C=1+(60-M)/(M+2),R=(files.size()+C-1)/C;//求列数C和行数R
        for(int i=0;i<60;++i)//输出60个'-'字符
            printf("-");
        puts("");//换行
        for(int i=0;i<R;++i){//输出R行
            for(int j=0;j<C;++j){//每行输出C列
                if(i+j*R>=files.size())
                    continue;
                printf("%s",files[i+j*R].c_str());
                int len=(j==C-1)?M:M+2;
                for(int k=0;k<len-files[i+j*R].size();++k)
                    printf(" ");
            }
            puts("");//换行
        }
    }
    return 0;
}
