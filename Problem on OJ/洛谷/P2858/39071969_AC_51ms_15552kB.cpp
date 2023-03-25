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
int a[2005];
int dp[2005][2005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		dp[i][i]=a[i]*n;
	}
	for(int L=2;L<=n;L++){
		for(int i=1;(i+L-1)<=n;i++){
			dp[i][(i+L-1)]=max(dp[i][(i+L-2)]+a[i+L-1]*(n-L+1),dp[i+1][i+L-1]+a[i]*(n-L+1));
		}
	}
	printf("%d",dp[1][n]);
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


