#include <iostream>
using namespace std;
int dp[300][10];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dp[i][1]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;i<=k;j++){
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][k];
    return 0;
}