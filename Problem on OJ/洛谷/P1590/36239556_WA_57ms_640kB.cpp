#include <iostream>
using namespace std;
int main(){
    long long t,n;
    cin>>t>>n;
    for(long long i=1;i<=t;i++){
        cin>>n;
        if(n%10>=7){
            cout<<n/10+1<<endl;
        }else{
            cout<<n/10<<endl;
        }
    }
    return 0;
}