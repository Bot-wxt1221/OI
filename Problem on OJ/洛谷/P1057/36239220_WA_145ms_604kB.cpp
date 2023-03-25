#include <iostream>
using namespace std;
int n,m;
int dp[35][35];
long long dfs(int n1,int m1);
int main(){
    cin>>n>>m;
	dp[2][1]=dp[n][1]=1;
	for(int j=2;j<=m;j++){
    	for(int i=n;i;i--){
			if(i==n){
				dp[i][j]=dp[1][j-1]+dp[n-1][j-1];
			}
			if(i==1){
				dp[i][j]=dp[n][j-1]+dp[2][j-1];
				continue;
			}
			dp[i][j]=dp[i-1][j-1]+dp[i+1][j-1];
		}
	}
	cout<<dp[1][1];
}