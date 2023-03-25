#include <iostream>
using namespace std;
int dp[1005][105];
int tc[105];
int sc[105];
int main(){
    int t,m;
    cin>>t>>m;
	for(int i=1;i<=m;i++){
		cin>>tc[i]>>sc[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=t;j;j--){
			if(j-tc[i]<0){
				dp[i][j]=dp[i-1][j];
				continue;
			}
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-tc[i]]+sc[i]);
		}
	}
	cout<<dp[m][t];
}