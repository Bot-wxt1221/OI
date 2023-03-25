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
int m[105],t[105];
int dp[205][205];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),am=read(),ak=read();
	for(int i=1;i<=n;i++){
		m[i]=read();
		t[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=am;j>=0;j--){
			for(int a=ak;a>=0;a--){
				if(j-m[i]>=0&&a-t[i]>=0)
					dp[j][a]=max(dp[j][a],dp[j-m[i]][a-t[i]]+1);
			} 
		}
	}
	printf("%d",dp[am][ak]);
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


