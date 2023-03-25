#include <iostream>
#include <cstdio>
inline int read();
int cost[150][200];
int dp[150][200];
int from[150][200];
int use[200];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("assigned.in","r",stdin);
	freopen("assigned.out","w",stdout);
	#endif
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cost[i][j]=read();
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            for(int k=1;k<=j;k++){
                if(dp[i][j]<=dp[i-1][j-k]+cost[i][k]){
                    dp[i][j]=dp[i-1][j-k]+cost[i][k];
                    from[i][j]=k;
                }
            }
        }
    }
    int now=m;
    for(int i=n;i>=1;i--){
        use[i]=from[i][now];
        now-=use[i];
    }
    printf("%d\n",dp[n][m]);
    for(int i=1;i<=n;i++){
        printf("%d %d\n",i,use[i]);
    }
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

