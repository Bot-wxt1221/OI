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
int dp[35][35];
int root[35][35];
int sc[35];
void dfs(int l,int r){
	if(l>r){
		dp[l][r]=1;
		return ;
	}
	if(l==r){
		dp[l][r]=sc[l];
		return ;
	}
	if(dp[l][r]){
		return ;
	}
	for(int i=l;i<=r;i++){
		dfs(l,i-1);
		dfs(i+1,r);
		if(dp[l][i-1]*dp[i+1][r]+sc[i]>=dp[l][r]){
			dp[l][r]=dp[l][i-1]*dp[i+1][r]+sc[i];
			root[l][r]=i;
		}
	}
	return ;
}
void dfs2(int l,int r){
	if(l>r){
		return ;
	}
	if(l==r){
		printf("%d ",l);
		return ;
	}
	printf("%d ",root[l][r]);
	dfs2(l,root[l][r]-1);
	dfs2(root[l][r]+1,r);
	return ;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		sc[i]=read();
	}
	dfs(1,n);
	printf("%lld\n",dp[1][n]);
	dfs2(1,n);
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


