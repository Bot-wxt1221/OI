#include <iostream>
using namespace std;
int a[1000];
int ans[1000];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i-1;j;j--){
            if(a[i]>a[j]){
                ans[i]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
}