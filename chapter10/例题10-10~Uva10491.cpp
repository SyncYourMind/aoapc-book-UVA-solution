#include<bits/stdc++.h>
using namespace std;
int main(){
    int cow,car,show;
    while(cin>>cow>>car>>show)
        printf("%.5f\n",(car*1.0*(car-1)+cow*1.0*car)/(cow+car)/(cow+car-1-show));
    return 0;
}
