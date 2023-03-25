#include <iostream>
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
int n,m;
inline int mod(int x){
	return x==1?m:x-1;
}
int dp[2005][2005];//在m小组进行到n步的最优解 
int dfs(int i,int j);
int to[2005][2005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			to[i][j]=read();
		}
	}
	unsigned long long ans=-1UL;
	for(int i=1;i<=m;i++){
		ans=min(ans,(unsigned long long )dfs(i,n));
	}
	cout<<ans;
	return 0;
}
int dfs(int i,int j){
	if(dp[i][j])	return dp[i][j];
	if(j==0)	return 0;
	return dp[i][j]=(min(dfs(mod(i),j-1),dfs(i,j-1))+to[i][j]);
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

