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
int w3[55];
int wei[55];
int mon[55];
int dp[400][500];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int max3,maxwei;
	max3=read();
	maxwei=read();
	int n=read();
	for(int i=1;i<=n;i++){
		w3[i]=read();
		wei[i]=read();
		mon[i]=read();
	}
	for(int m=1;m<=n;m++){
		for(int i=max3;i>=w3[m];i--){
			for(int j=maxwei;j>=wei[m];j--){
				dp[i][j]=max(dp[i][j],dp[i-w3[m]][j-wei[m]]+mon[m]);
			}
		}
	}
	printf("%d",dp[max3][maxwei]);
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


