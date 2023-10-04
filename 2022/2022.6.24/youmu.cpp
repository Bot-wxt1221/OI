#include <iostream>
#include <cstdio>
#include <cmath>
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
bool map[1005][1005];
int dp[1005][1005];
int ans=0;
int n,m;
int dfs(int x,int y,int step);
int main(){
	freopen("youmu.in","r",stdin);
	freopen("youmu.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y;
		y=read();
		if(abs(x)<=n&&abs(y)<=n){
			map[x+105][y+105]=1;
		}
	}
	printf("%d",dfs(105,105,0));
	return 0;
}
int dfs(int x,int y,int step){
	if(map[x][y]){
		return 0;
	}
	if(step==n){
		return 1;
	}
	if(dp[x][y]){
		return dp[x][y];
	}
	map[x][y]=1;
	dp[x][y]+=dfs(x+1,y,step+1);
	dp[x][y]+=dfs(x-1,y,step+1);
	dp[x][y]+=dfs(x,y+1,step+1);
	map[x][y]=0;
	dp[x][y]%=998244853;
	return dp[x][y];
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


