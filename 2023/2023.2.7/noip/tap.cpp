#include <iostream>
#include <cstdio>
#define int unsigned long long
inline int read();
int dp[50];
int dfs(int n){
	if(n==1){
		return 1;
	}
	if(dp[n]){
		return dp[n];
	}
	int &cnt=dp[n];
	for(int i=1;i<=n/2;i++){
		if(i==n-i){
			cnt+=((dfs(i))*(dfs(n-i)+1))/2;
		}else{
			cnt+=(dfs(i))*dfs(n-i);
		}
	}
	for(int i=1;i<=n/3;i++){
		for(int j=i;j<=(n-i)/2;j++){
			if(i==j&&n-i-j==i){
				cnt+=(dfs(i))*(dfs(j)+1)*(dfs(n-i-j)+2)/6;
			}else if(i==j){
				cnt+=(dfs(i))*(dfs(j)+1)*(dfs(n-i-j))/2;
			}else if(n-j-i==i){
				cnt+=(dfs(i)+1)*(dfs(j))*(dfs(n-i-j))/2;
			}else if(n-j-i==j){
				cnt+=(dfs(i))*(dfs(j)+1)*(dfs(n-i-j))/2;
			}else{
				cnt+=(dfs(i))*(dfs(j))*(dfs(n-i-j));
			}
		}
	}
	return cnt;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("tap.in","r",stdin);
	freopen("tap.out","w",stdout);
	#endif
    int n=read();
	dp[1]=1;
	printf("%lld",dfs(n));
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

