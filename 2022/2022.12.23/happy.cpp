#include <iostream>
#include <cstdio>
inline int read();
int v[30];
int dp[30006];
int p[30];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	#endif
    int n=read(),m=read();
    for(int i=1;i<=m;i++){
        v[i]=read();
        p[i]=read();
    }
    for(int i=1;i<=m;i++){
        for(int j=n;j>=v[i];j--){
            dp[j]=std::max(dp[j],dp[j-v[i]]+v[i]*p[i]);
        }
    }
    printf("%d",dp[n]);
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

