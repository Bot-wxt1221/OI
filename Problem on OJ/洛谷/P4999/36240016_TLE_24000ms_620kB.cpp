#include <iostream>
using namespace std;
int main(){
    int t,l,r;
    unsigned long long ans=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>l>>r;
        ans=0;
        for(int j=l;j<=r;j++){
            int temp=j;
            while(j){
                ans=j%10+ans;
                j=j/10;
            }
        }
        cout<<ans%1000000007;
    }
}