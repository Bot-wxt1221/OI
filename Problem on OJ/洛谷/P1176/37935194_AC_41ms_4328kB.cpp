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
int dp[1005][1005]; 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read();
		int y=read();
		dp[x][y]=-1;
	}
	dp[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j&&i==1){
				continue;
			}
			if(dp[i][j]!=-1){
				dp[i][j]=(dp[i-1][j]==-1?0:dp[i-1][j])+(dp[i][j-1]==-1?0:dp[i][j-1]);
			}
			dp[i][j]%=100003;
		}
	}
	printf("%d",dp[n][n]==-1?0:dp[n][n]);
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


