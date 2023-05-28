#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int dp[1000006];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	#endif
    int n=read(),m=read();
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int a=read();
        for(int j=a;j<=m;j++){
            dp[j]+=dp[j-a];
        }
    }
    printf("%lld",dp[m]);
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

Description:

Example:
	1:
		In:

		Out:
More:

*/

