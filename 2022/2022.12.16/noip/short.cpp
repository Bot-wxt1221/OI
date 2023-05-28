#include <iostream>
#include <cstdio>
inline int read();
int map[25][25];
int dp[25][25];
int go[25][25];
void dfs(int l,int r){
    // printf("%d ",l);
    if(go[l][r]!=0){
        dfs(l,go[l][r]);
        dfs(go[l][r],r);
    }else{
        printf("%d ",r);
    }
    // printf("%d ",r);
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("short.in","r",stdin);
	freopen("short.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=read();
            if(map[i][j]==0){
                dp[i][j]=0x3f3f3f3f;
            }else{
                dp[i][j]=map[i][j];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    go[i][j]=k;
                }
            }
        }
    }
    printf("minlong=%d\n",dp[1][n]);
    dfs(1,n);
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

