#include <iostream>
using namespace std;
int dp[45][10];
int main(){
    string a;
    int n,k;
    cin>>n>>k>>a;
    for(int i=1;i<=n;i++){
        for(int j=k;j<=0;j--){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]*a[i]);
        }
    }
    cout<<dp[n][k];
}