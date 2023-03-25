#include <iostream>
#include <cstring>
#include <cstdio>
#define int long long
using namespace std;
int n,m1;
int _min;
int a[1005][1005];
int dp[1005][1005][2];
int dfs(int x,int y,int m){
	if(dp[x][y][m]>_min){
		return dp[x][y][m];
	}
	if(x<1||y<1||x>n||y>m1){
		return _min;
	}
	return dp[x][y][m]=max(max(dfs((x+(m==0?1:-1)),y,m),dfs(x,y-1,0)),dfs(x,y-1,1))+a[x][y];
}
signed main(){
	memset(dp,-0x3f,sizeof(dp));
	_min=dp[1][1][1];
	scanf("%lld%lld",&n,&m1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m1;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	dp[1][1][0] = dp[1][1][1] = a[1][1];
//	dfs(0,4,1);
	printf("%lld",max(dfs(n,m1,0),dfs(n,m1,1)));
	return 0;
}