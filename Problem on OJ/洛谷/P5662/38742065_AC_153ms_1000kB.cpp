#include <iostream>
#include <cstring>
#include <cstdio>
#define int long long
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
int p[1005][1005];
int have[1005];
int dp[10005];
signed main(){
//	freopen("souvenir.in","r",stdin);
//	freopen("souvenir.out","w",stdout);
	int t=read(),n=read(),m=read();
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			p[i][j]=read();
		}
	}
	for(int i=1;i<=t;i++){
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=n;j++){
			for(int a=p[i][j];a<=m;a++){
				dp[a]=max(dp[a],dp[a-p[i][j]]+p[i+1][j]-p[i][j]);
			}
		}
		m+=dp[m];
	}
	printf("%lld",m);
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


