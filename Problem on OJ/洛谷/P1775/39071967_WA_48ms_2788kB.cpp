#include <iostream>
#include <cstring>
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
int a[1050];
int he[1050];
int dp[1005][1005];
int dp2[1005][1005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		he[i]=he[i-1]+a[i];
		dp2[i][i]=0;
	}
	for(int L=2;L<=n;L++){
		for(int i=1;(i+L-1)<n;i++){
			dp2[i][i+L-1]=0x3f3f3f3f;
			for(int k=i;k<i+L-1;k++){
				dp[i][i+L-1]=max(dp[i][i+L-1],dp[i][k]+dp[k+1][i+L-1]);
				dp2[i][i+L-1]=min(dp2[i][i+L-1],dp2[i][k]+dp2[k+1][i+L-1]);
			}
			dp[i][i+L-1]+=he[i+L-1]-he[i-1];
			dp2[i][i+L-1]+=he[i+L-1]-he[i-1];
		}
	}
	int as1=0,as2=0x3f3f3f3f;
	printf("%d",dp2[1][n]);
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


