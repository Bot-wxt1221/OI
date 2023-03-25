#include <iostream>
using namespace std;
int main(){
    char a;
    int d=0,t=0;
    long long ans=0;
    while(scanf("%c",&a)!='\n'){
        scanf("%d",&d);
        if(a=='*'){
            t=t*d%10000;
        }
        else{
            ans+=t;ans=ans%10000;t=ans;
        }
    }
}