#include <iostream>
using namespace std;
int ans[10005];
int main(){
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ans[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;i++){
            if(ans[j]>ans[i]){
                sum++;
            }
        }
    }
    cout<<sum;
}