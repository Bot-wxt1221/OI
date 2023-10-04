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
int dp[1005];
int dfs(int a);
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n=read();
	dp[1]=1;
	cout<<dfs(n);
	return 0;
}
int dfs(int a){
	if(dp[a])	return dp[a];
	int ans=0;
	for(int i=1;i<=a/2;i++){
		ans+=dfs(i);
	}
	ans++;
	return dp[a]=ans;
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


