#include <iostream>
using namespace std;
int dp[300][300];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dp[i][1]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=k;j++){
        	if(i>=j)
            	dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
        }
    }
    cout<<dp[n][k];
    return 0;
}