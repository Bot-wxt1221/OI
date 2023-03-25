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
int dp[10005];
int k[10005];
int m[10005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int v=read(),n,c;
	n=read();
	c=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		m[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=c;j>=1;j--){
			if(j-m[i]>=0)
				dp[j]=max(dp[j],dp[j-m[i]]+k[i]);
		}
	}
	for(int i=1;i<=c;i++){
		if(dp[i]>=v){
			printf("%d",c-i);
			return 0;
		}
	}
	printf("Impossible");
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


