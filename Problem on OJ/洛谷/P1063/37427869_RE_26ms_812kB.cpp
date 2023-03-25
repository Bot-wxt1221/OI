#include <iostream>
#include <cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int dp[105][105][3];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		int temp=read();
		dp[i][i][0]=temp;
		dp[i-1][i-1][1]=temp;
		dp[i+n][i+n][0]=temp;
		dp[i-1+n][i-1+n][1]=temp;
	}
	dp[n*2][n*2][1]=dp[0][0][1];
	for(int L=2;L<=n*2;L++){
		for(int i=1;(i+L-1)<=n*2;i++){
			int j=i+L-1;
			for(int k=i;k<j;k++){
				int temp=dp[i][k][2]+dp[k+1][j][2]+dp[i][k][0]*dp[i][k][1]*dp[k+1][j][1];
				if(temp>dp[i][j][2]){
					dp[i][j][2]=temp;
					dp[i][j][0]=dp[i][k][0];
					dp[i][j][1]=dp[k+1][j][1];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n+1;i++){
		ans=max(ans,dp[i][i+n-1][2]);
	}
	printf("%d",ans);
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


