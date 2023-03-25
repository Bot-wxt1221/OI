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
int dp[300][300];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		dp[i][i]=read();
	}
	int ans=0;
	for(int L=2;L<=n;L++){
		for(int i=1;(i+L-1)<=n;i++){
			int j=i+L-1;
			for(int k=i;k<j;k++){
				if(dp[i][k]!=dp[k+1][j]){
				}else{
					dp[i][j]=max(dp[i][j],dp[i][k]+1);
					ans=max(ans,dp[i][j]);
				}
			}
		}
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


