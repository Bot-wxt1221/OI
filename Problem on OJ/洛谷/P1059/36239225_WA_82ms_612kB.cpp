#include <iostream>
using namespace std;
bool ans[1005];
int main(){
    int n,temp;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>temp;
        ans[temp]=1;
    }
    for(int i=0;i<1005;i++){
        if(ans[i]){
            cout<<i<<' ';
        }
    }
    return 0;
}