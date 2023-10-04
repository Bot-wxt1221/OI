#include <iostream>
#include <cstdio>
inline int read();
int map[105][105];
int dp[105][105];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("peanut.in","r",stdin);
	freopen("peanut.out","w",stdout);
	#endif
    int t=read();
    while(t--){
        int r=read(),c;
        c=read();
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                map[i][j]=read();
            }
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                dp[i][j]=std::max(dp[i-1][j],dp[i][j-1])+map[i][j];
            }
        }
        printf("%d\n",dp[r][c]);
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

