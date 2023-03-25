#include <iostream>
#include <algorithm>
using namespace std;
long long ans[2000000];
int main(){
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>ans[i];
    }
    sort(ans,ans+m);
    for(int i=0;i<m;i++){
        cout<<ans[i]<<' ';
    }
}