#include <iostream>
using namespace std;
int aa[55][55];
int dp[55][55][55][55];
int _ans=0;
int max(int a,int b,int c,int d){
	return max(max(a,b),max(c,d));
}
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>aa[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int i2=1;i2<=n;i2++){
				for(int j2=1;j2<=m;j2++){
					dp[i][j][i2][j2]=max(dp[i-1][j][i2-1][j2],dp[i-1][j][i2][j2-1],dp[i][j-1][i2-1][j2],dp[i][j-1][i2][j2-1])+aa[i][j]+aa[i2][j2];
					if(i==i2&&j==j2){
						dp[i][j][i2][j2]-=aa[i][j];
					}
				}
			}
		}
	}
	cout<<dp[n][n][n][n];
}