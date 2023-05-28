
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
int dp[105][105];
int a[105];
int s[105];
int main(){
	freopen("snow.in","r",stdin);
	freopen("snow.out","w",stdout);
	int n=read(),k;
	k=read();
	for(int i=1;i<=n;i++){
        a[i]=read();
        s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            for(int m=1;m<=i;m++){
                dp[i][j]=max(dp[i][j],dp[m][j]);
                dp[i][j]=max(dp[i][j],dp[m-1][j-1]+s[i]-s[m-1]);
            }
        }
	}
	printf("%d",dp[n][k]);
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

