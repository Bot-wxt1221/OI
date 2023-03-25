#include <iostream>
using namespace std;
long long dp[1005][105];
long long tc[105];
long long sc[105];
int main(){
    int t,m;
    cin>>t>>m;
	for(int i=1;i<=m;i++){
		cin>>sc[i]>>tc[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=t;j++){
			if(j-tc[i]<0){
				dp[i][j]=dp[i-1][j];
				continue;
			}
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-tc[i]]+sc[i]);
		}
	}
    cout<<dp[m][t];
}