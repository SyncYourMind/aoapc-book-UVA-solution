#include<bits/stdc++.h>
using namespace std;
int main(){
    string down,up;
    while(cin>>up>>down){
        if(up.size()<down.size())
            swap(up,down);
        int result=INT_MAX;
        for(int i=-down.size();i<(int)up.size();++i){
            for(int j=0;j<down.size();++j){
                int m=i+j<0||i+j>=up.size()?0:up[i+j]-'0';
                if(m+down[j]-'0'>3)
                    goto loop;
            }
            if(i<0)
                result=min(result,(int)(up.size()-i));
            else if(i<up.size()-down.size())
                result=min(result,(int)(up.size()));
            else
                result=min(result,(int)(i+down.size()));
loop:;
        }
        printf("%d\n",result);
    }
    return 0;
}
