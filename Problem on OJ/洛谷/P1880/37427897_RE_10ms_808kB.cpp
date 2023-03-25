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
int a[105];
int he[105];
int dp[105][105];
int dp2[105][105];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		a[i+n]=a[i];
		he[i]=he[i-1]+a[i];
		dp2[i][i]=0;
	}
	for(int i=n+1;i<=2*n;i++){
		he[i]=he[i-1]+a[i];
		dp2[i][i]=0;
	}
	for(int L=2;L<=n;L++){
		for(int i=1;(i+L-1)<n*2;i++){
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
	for(int i=1;i+n-1<n*2;i++){
		as1=max(as1,dp[i][i+n-1]);
		as2=min(as2,dp2[i][i+n-1]);
	}
	printf("%d\n%d",as2,as1);
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


