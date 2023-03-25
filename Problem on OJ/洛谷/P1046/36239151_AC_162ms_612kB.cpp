#include <iostream>
using namespace std;
int main(){
    int n[10];
    for(int i=0;i<10;i++){
        cin>>n[i];
    }
    int t;
    cin>>t;
    t=t+30;
    int ans=0;
    for(int i=0;i<10;i++){
        if(n[i]<=t){
            ans++;
        }
    }
    cout<<ans;
}