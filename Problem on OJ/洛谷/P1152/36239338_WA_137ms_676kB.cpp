#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[1005];
int ans[1005];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        ans[i]=abs(a[i]-a[i-1]);
    }
    sort(ans+2,ans+n+1);
    bool c=1;
    for(int i=2;i<=n;i++){
        if(ans[i]!=i){
            c=0;
        }
    }
    if(c){
        cout<<"Jolly";
    }
    else{
        cout<<"Not jolly";
    }
}