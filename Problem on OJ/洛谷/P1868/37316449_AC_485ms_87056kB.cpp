#include <iostream>
#include <cstdio>
#include <vector>
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
vector<int>a[3000005];
int yuejie[100];
int dp[3000005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		int c=read();
		int b=read();
		a[b].push_back(c);
	}
	for(int i=0;i<=3000000;i++){
		dp[i]=dp[i-1];
		for(int j=0;j<a[i].size();j++){
			dp[i]=max(dp[i],dp[a[i][j]-1]+(i-a[i][j]+1));
		}
	}
	printf("%d",dp[3000000]);
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


