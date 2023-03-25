#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int cost[20];
int dp[1000005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("busses.in","r",stdin);
	freopen("busses.out","w",stdout);
	#endif
    for(int i=1;i<=10;i++){
        cost[i]=read();
    }
    int V=read();
    for(int i=1;i<=V;i++){
        dp[i]=0x3f3f3f3f;
        for(int j=1;j<=std::min(10ll,i);j++){
            dp[i]=std::min(dp[i],dp[i-j]+cost[j]);
        }
    }
    printf("%lld",dp[V]);
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

