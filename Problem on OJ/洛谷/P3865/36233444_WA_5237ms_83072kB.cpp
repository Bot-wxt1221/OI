#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int dp[100005][210];
int a[100005];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][0]=a[i];
	}
	for(int j=1;j<=log2(n);j++){
		for(int i=1;(int(1<<(j-1))+i)<n;i++){
			dp[i][j]=max(dp[i][j-1],dp[(1<<(j-1))+i][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		cout<<max(dp[a][int(log2(b-a+1))],dp[b-(1<<int(log2(b-a+1)))+1][int(log2(b-a+1))])<<endl;
	}
	return 0;
}