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
int n,k;
int dp[2005][2005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		dp[1][i]=1;
	}
	for(int i=2;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int m=1;m*j<=n;m++){
				dp[i][j]+=dp[i-1][m*j];
				dp[i][j]%=1000000007;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+dp[k][i])%1000000007;
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


