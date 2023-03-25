#include <iostream>
#include <algorithm>
using namespace std;
long long ans[5000005];
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>ans[i];
    }
    nth_element(ans,ans+n,ans+m);//简短又高效
    cout<<ans[n];
}