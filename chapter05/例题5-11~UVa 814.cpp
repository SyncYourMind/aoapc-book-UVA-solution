#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;//输入字符串
    unordered_set<string>users;//按“姓名@城市”格式存储邮件地址
    while(cin>>line&&line!="*"){//当输入字符串不是"*"时继续循环
        string designation,name;
        int num;
        cin>>designation>>num;
        for(int i=0;i<num;++i){//按“姓名@城市”格式存储邮件地址
            cin>>name;
            users.insert(name+"@"+designation);
        }
    }
    while(cin>>line&&line!="*"){//当输入字符串不是"*"时继续循环
        vector<string>designation,mail;//按输入顺序存储城市名、存储邮件内容
        unordered_map<string,vector<string>>name;//按输入顺序存储城市名对应的姓名
        //存储发件人姓名、发件人所在城市
        string senderName=line.substr(0,line.find('@')),senderDes=line.substr(line.find('@')+1);
        while(cin>>line&&line!="*"){//当输入字符串不是"*"时继续循环
            int i=line.find('@');//找到'@'字符在line字符串中的下标
            string n=line.substr(0,i),d=line.substr(i+1);//分割姓名、城市
            if(name.find(d)==name.end())//如果该城市名是第一次出现
                designation.push_back(d);//存入城市名列表中
            if(find(name[d].begin(),name[d].end(),n)==name[d].end())//如果姓名没有重复
                name[d].push_back(n);//存入姓名列表中
        }
        getline(cin,line);//吸收换行符
        while(getline(cin,line)&&line!="*")//读取邮件内容
            mail.push_back(line);
        for(int i=0;i<designation.size();++i){//进行输出
            printf("Connection between %s and %s\n",senderDes.c_str(),designation[i].c_str());
            printf("     HELO %s\n     250\n",senderDes.c_str());
            printf("     MAIL FROM:<%s@%s>\n     250\n",senderName.c_str(),senderDes.c_str());
            bool f=false;//标志是否有收件人存在
            for(int j=0;j<name[designation[i]].size();++j){
                string n=name[designation[i]][j]+"@"+designation[i];
                printf("     RCPT TO:<%s>\n",n.c_str());
                if(users.find(n)==users.end())
                    printf("     550\n");
                else{
                    f=true;//有收件人存在
                    printf("     250\n");
                }
            }
            if(f){//有收件人存在输出邮件正文
                printf("     DATA\n     354\n");
                for(string&j:mail)
                    printf("     %s\n",j.c_str());
                printf("     .\n     250\n");
            }
            printf("     QUIT\n     221\n");
        }
    }
    return 0;
}
