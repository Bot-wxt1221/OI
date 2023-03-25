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
int dp[105][105];
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
    int n=read();
    int m=read();
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        int a=read();
        for(int j=0;j<=m;j++){
            for(int k=0;k<=min(j,a);k++){
                dp[i][j]+=dp[i-1][j-k];
                dp[i][j]%=1000007;
            }
        }
    }
    printf("%d",dp[n][m]);
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
