#include <stdio.h>
int main(){
    for(int a=1;a<=9;++a)
        for(int b=1;b<=9;++b)
            if(a!=b)
                for(int c=1;c<=9;++c)
                    if(a!=c&&b!=c)
                        for(int d=1;d<=9;++d)
                            if(a!=d&&b!=d&&c!=d)
                                for(int e=1;e<=9;++e)
                                    if(a!=e&&b!=e&&c!=e&&d!=e)
                                        for(int f=1;f<=9;++f)
                                            if(a!=f&&b!=f&&c!=f&&d!=f&&e!=f)
                                                for(int g=1;g<=9;++g)
                                                    if(a!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g)
                                                        for(int h=1;h<=9;++h)
                                                            if(a!=h&&b!=h&&c!=h&&d!=h&&e!=h&&f!=h&&g!=h)
                                                                for(int i=1;i<=9;++i)
                                                                    if(a!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i){
                                                                        int k1=a*100+b*10+c,k2=d*100+e*10+f,k3=g*100+h*10+i;
                                                                        if(k1*2==k2&&k1*3==k3)
                                                                            printf("%d %d %d\n",k1,k2,k3);
                                                                    }
    return 0;
}
