#include <iostream>
#include <cstdio>
inline int read();
int dp[20005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("boxes.in","r",stdin);
	freopen("boxes.out","w",stdout);
	#endif
    int V=read();
    int n=read();
    for(int i=1;i<=n;i++){
        int a=read();
        for(int j=V;j>=a;j--){
            dp[j]=std::max(dp[j],dp[j-a]+a);
        }
    }
    printf("%d",V-dp[V]);
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

