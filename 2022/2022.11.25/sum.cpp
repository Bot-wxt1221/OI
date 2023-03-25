#include <iostream>
#include <cstdio>
inline int read();
int a[1005];
int dp[1005][2];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        dp[i][0]=std::max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=dp[i-1][0]+a[i];
    }
    printf("%d",std::max(dp[n][0],dp[n][1]));
	return 0;
}
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
/*
Anything about this program:
Type:
    Example
Description:
    最大数字和，不能去相邻的。
Example:
	1:
		In:
            5
            5 4 6 1 4
		Out:
            15
    2:
        In:
            10
            218 56 123 65 34 76 34 76 54 765
        Out:
            1258
    3:
        In:
            13
            1 1 4 5 1 4 1 9 1 9 8 1 0
        Out:
            29
    4:
        In:
            5
            1 2 3 4 5
        Out:
            9
More:
    
*/


