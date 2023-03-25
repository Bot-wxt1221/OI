#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
inline int read();
int a[20][20];
int dp[20][20],n,m,r,c;
int w[20];
int v[20][20];
int rec[20];
int ans=0x3f3f3f3f;
void go();
void dfs(int x,int y)
{
    if(y>r)
    {
        go();
        return;
    }
    if (x>n) return;
    dfs(x+1,y);
    rec[y]=x;
    dfs(x+1,y+1);
}
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("submatrix.in","r",stdin);
	freopen("submatrix.out","w",stdout);
	#endif
    n=read();
    m=read();
    r=read();
    c=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=read();
        }
    }
    dfs(1,1);
    printf("%d",ans);
	return 0;
}
void go(){
    memset(dp,127,sizeof(dp));
    memset(w,0,sizeof(w));
    memset(v,0,sizeof(v));
    for(int i=1;i<=m;i++){
        for(int j=1;j<r;j++){
            w[i]+=std::abs(a[rec[j]][i]-a[rec[j+1]][i]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            for(int k=1;k<=r;k++){
                v[i][j]+=std::abs(a[rec[k]][i]-a[rec[k]][j]);
            }
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=c;i++){
        for(int j=i;j<=m;j++){
            for(int k=0;k<j;k++){
                dp[i][j]=std::min(dp[i-1][k]+w[j]+v[k][j],dp[i][j]);
            }
        }
    }
    for(int i=c;i<=m;i++){
        ans=std::min(ans,dp[c][i]);
    }
    return ;
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


