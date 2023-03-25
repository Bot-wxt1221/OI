#include <iostream>
#include <cstdio>
#include <cstring>
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
int r[205][205];
int dp[205];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			r[i][j+i]=read();
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){ 
			dp[i]=min(dp[i],dp[j]+r[j][i]); 
		}
	}
	printf("%d",dp[n]);
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

