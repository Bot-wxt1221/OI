#include <iostream>
#include <cstdio>
using namespace std;
inline int read();
int dp[105][105];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),m=read();
    for(int i=1;i<=m;i++){
        int a=read();
        int b=read();
        dp[a][b]=1;
    }
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]|=(dp[i][k]&&dp[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int aa=1;
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			aa=aa&(dp[i][j]||dp[j][i]);
		}
		ans+=aa;
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


