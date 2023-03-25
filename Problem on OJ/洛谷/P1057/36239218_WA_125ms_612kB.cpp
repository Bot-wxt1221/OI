#include <iostream>
using namespace std;
int n,m;
int dp[35][35];
long long dfs(int n1,int m1);
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    	dp[n][i]=1;
	}
    for(int i=n-1;i;i--){
    	for(int j=m-1;j;j--){
			if(i==1){
				dp[i][j]=dp[n][j+1]+dp[2][j+1];
				continue;
			}
			dp[i][j]=dp[i-1][j+1]+dp[i+1][j+1];
		}
	}
	cout<<dp[1][1];
}