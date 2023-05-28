#include <iostream>
#include <cstdio>
inline int read();
int dp[1005][1005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	#endif
    int R=read();
    for(int i=1;i<=R;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=read()+std::max(dp[i-1][j],dp[i-1][j-1]);
        }
    }
    int ans=-0x3f3f3f3f;
    for(int i=1;i<=R;i++){
        ans=std::max(ans,dp[R][i]);
    }
    printf("%d",ans);
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

