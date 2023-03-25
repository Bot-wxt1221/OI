#include <iostream>
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
int lose[1005];
int win[1005];
int use[1005];
int dp[1005];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	int x=read();
	for(int i=1;i<=n;i++){
		lose[i]=read();
		win[i]=read();
		use[i]=read();
	}
	for(int j=1;j<=n;j++){
		for(int i=x;i>=0;i--){
			if(i<use[j]){
				dp[i]+=lose[j];
			}else{
				dp[i]=max(dp[i]+lose[j],dp[i-use[j]]+win[j]);
			}
		}
	}
	printf("%lld",dp[x]*5);
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


