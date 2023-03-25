#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int pow(int a,int b){
    if(b==0){
        return 1;
    }
    if(b%2==1){
        int temp=pow(a,b-1);
        if(temp==-1){
            return -1;
        }
        if(temp*a>1000000000ll){
            return -1;
        }
        return temp*a;
    }else{
        int temp=pow(a,b/2);
        if(temp==-1){
            return -1;
        }
        if(temp*temp>1000000000ll){
            return -1;
        }
        return temp*temp;
    }
}
signed main(){
    int a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",pow(a,b));
}