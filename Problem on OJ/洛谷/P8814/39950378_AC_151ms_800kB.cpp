#include <iostream>
#include <cmath>
#include <cstdio>
#define int long long
using namespace std;
signed main(){
    int k;
    scanf("%lld",&k);
    while(k--){
        int n,d,e;
        scanf("%lld%lld%lld",&n,&d,&e);
        int m=n-e*d+2;
        int temp=sqrt(m*m-4*n);
        int p=(temp+m)/2;
        int q=n/p;
        if(p*q==n&&e*d==(p-1)*(q-1)+1){
            if(p>q){
                swap(p,q);
            }
            printf("%lld %lld\n",p,q);
        }else{
            printf("NO\n");
        }
    }
    return 0;
}