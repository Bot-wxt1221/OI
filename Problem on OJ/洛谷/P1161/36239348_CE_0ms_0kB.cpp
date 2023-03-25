#include <iostream>
#include <cmath>
using namespace std;
bool c[2000005];
int main(){
    int n,t,sum=0;
    double a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>t;
        for(int j=1;j<=t;j++){
            c[floor(j*a)]=c[floor(j*a)]^1;
            sum=max(sum,floor(j*a));
        }
    }
    for(int i=1;i<=sum;i++){
        if(c[i]){
            cout<<i;
            return 0;
        }
    }
}