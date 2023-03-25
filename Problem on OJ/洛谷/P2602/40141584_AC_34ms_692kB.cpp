#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int dp[20],ans1[20],ans2[20],mi[20];
int a[20];
void solve(int n,int *ans);
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int a=read(),b=read();
	mi[0]=1;
	for(int i=1;i<=19;i++){
		dp[i]=dp[i-1]*10+mi[i-1];
		mi[i]=mi[i-1]*10;
	}
	solve(a-1,ans1);
	solve(b,ans2);
	for(int i=0;i<10;i++){
		printf("%lld ",ans2[i]-ans1[i]);
	}
	return 0;
}
void solve(int n,int *ans){
	int tmp = n;
	int len = 0;
	while (n) a[++len] = n % 10, n = n/10;
	for (int i = len; i >= 1; --i) {
		for (int j = 0; j < 10; j++) ans[j] += dp[i - 1] * a[i];
		for (int j = 0; j < a[i]; j++) ans[j] += mi[i - 1];
		tmp -= mi[i - 1] * a[i], ans[a[i]] += tmp + 1;
		ans[0] -= mi[i - 1];
	}
	return ;
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

