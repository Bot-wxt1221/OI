#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    int a;
    cin>>ans;
    for(int i=1;i<n;i++){
        cin>>a;
        ans=min(ans,a);
    }
    cout<<ans;
}