#include <iostream>
#include <cstdio>
inline int read();
int dp[205];
int w[35];
int c[35];
int p[35];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	#endif
    int V=read();
    int n=read();
    int T=read();
    for(int i=1;i<=n;i++){
        w[i]=read();
        c[i]=read();
        p[i]=read();
    }
    for(int i=1;i<=T;i++){
        for(int am=V;am>=0;am--){
            for(int a=1;a<=n;a++){
                if(p[a]!=i||am<w[a]){
                    continue;
                }
                dp[am]=std::max(dp[am],dp[am-w[a]]+c[a]);
            }
        }
    }
    printf("%d",dp[V]);
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

