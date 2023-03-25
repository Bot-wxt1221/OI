#include <iostream>
using namespace std;
int main(){
    long long t,n;
    cin>>t;
    for(long long i=1;i<=t;i++){
        cin>>n;
        long long count=0;
        bool can=0;
        for(long long j=1;j<=n;j++){
            can=1;
            int temp=j;
            while(temp){
                if(temp%10==7){
                    can=0;
                    break;
                }
                temp=temp/10;
            }
            if(can){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}