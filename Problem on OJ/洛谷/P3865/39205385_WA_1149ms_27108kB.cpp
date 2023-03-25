#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
inline int read();
int dp[1000005][32];
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		dp[i][0]=read();
	}
	for(int k=1;k<=log2(n);k++){
		for(int i=1;i<=n;i++){
			dp[i][k]=max(dp[i][k-1],dp[i+(1<<(k-1))][k-1]);
		}
	}
	for(int i=1;i<=m;i++){
		int l,r;
		l=read();
		r=read();
		int k=log2(r-l+1);
		printf("%lld\n",max(dp[l][k],dp[r-(1<<k)][k]));
	}
	return 0;
}
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


