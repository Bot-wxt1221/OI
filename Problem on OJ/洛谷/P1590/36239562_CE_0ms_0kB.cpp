#include <iostream>
using namespace std;
int main(){
    long long t,n,ans=1;
    cin>>t;
    for(long long i=1;i<=t;i++){
        cin>>n;
        while(n>=10){
        if(n%10>=7){
            ans=ans*(n);
        }else{
            ans=ans*(n+1);
        }
        n=n/10;
        }
        if(n%10>=7){
            ans=ans*(n-1);
        }else{
            ans=ans*(n);
        }
        cout<<ans<<<endl;
    }
    return 0;
}