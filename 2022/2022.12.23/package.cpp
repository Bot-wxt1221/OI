#include <iostream>
#include <cstdio>
inline int read();
int w[35],v[35];
int dp[205];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("package.in","r",stdin);
	freopen("package.out","w",stdout);
	#endif
    int m=read(),n=read();
    for(int i=1;i<=n;i++){
        w[i]=read();
        v[i]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=std::max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%d",dp[m]);
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

