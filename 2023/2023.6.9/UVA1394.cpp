#include <iostream>
#include <cstdio>
inline int read();
int dp[100005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	int n,k,m;
    while(scanf("%d%d%d",&n,&k,&m)&&n!=0&&k!=0&&m!=0){
		dp[0]=0;
		for(int i=1;i<=n;i++){
			dp[i]=(dp[i-1]+k)%i;
		}
		printf("%d\n",(dp[n-1]+m)%n+1);
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


