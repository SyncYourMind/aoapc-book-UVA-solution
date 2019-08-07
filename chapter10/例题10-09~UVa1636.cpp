#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    while(cin>>line){
        int num0=0,num00=0;
        for(int i=0;i<line.size();++i)
            if(line[i]=='0'){
                ++num0;
                if(line[(i+1)%line.size()]=='0')
                    ++num00;
            }
        double rotate=num0*1.0/line.size(),shoot=num00*1.0/num0;
        puts(fabs(rotate-shoot)<1e-6?"EQUAL":rotate-shoot>0?"ROTATE":"SHOOT");
    }
    return 0;
}
