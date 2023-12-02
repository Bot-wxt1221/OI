#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int a[105];
int dp[105][105];
int sum[105];
int getsum(int i,int j){
	return sum[j]-sum[i-1];
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n;
    while(scanf("%lld",&n)!=EOF&&n!=0){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			a[i]=read();
			sum[i]=a[i]+sum[i-1];
			dp[i][i]=a[i];
		}
		for(int siz=2;siz<=n;siz++){
			for(int i=1;i+siz-1<=n;i++){
				int j=i+siz-1;
				dp[i][j]=getsum(i,j);
				for(int k=i;k<=j;k++){
					if(k!=i)
						dp[i][j]=std::max(dp[i][j],getsum(i,j)-dp[k][j]);
					if(k!=j)
						dp[i][j]=std::max(dp[i][j],getsum(i,j)-dp[i][k]);
				}
			}
		}
		printf("%lld\n",dp[1][n]-(sum[n]-dp[1][n]));
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


