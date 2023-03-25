#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
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
int nxf[1005],nyf[1005];
int nxb[1005],nyb[1005];
char fj[1006];
char be[1006];
int dp[1005][1005];
int a[257];
int to[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dis(int x,int y,int nx,int ny){
    return (x-nx)*(x-nx)+(y-ny)*(y-ny);
}
signed main(){
	int n=read();
    int m=read();
    int fx=read();
    int fy=read();
    int bx=read();
    int by=read();
    nxf[0]=fx;
    nyf[0]=fy;
    nxb[0]=bx;
    nyb[0]=by;
    a['N']=0;
    a['E']=1;
    a['S']=2;
    a['W']=3;
    scanf("%s",fj);
    scanf("%s",be);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        int t=a[fj[i-1]];
        fx+=to[t][0];
        fy+=to[t][1];
        nxf[i]=fx;
        nyf[i]=fy;
    }
    for(int i=1;i<=m;i++){
        int t=a[be[i-1]];
        bx+=to[t][0];
        by+=to[t][1];
        nxb[i]=bx;
        nyb[i]=by;
    }
    for(int i=1;i<=m;i++){
        dp[0][i]=dis(nxf[0],nyf[0],nxb[i],nyb[i])+dp[0][i-1];
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=dis(nxb[0],nyb[0],nxf[i],nyf[i])+dp[i-1][0];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+dis(nxf[i],nyf[i],nxb[j],nyb[j]);
        }
    }
    printf("%lld",dp[n][m]);
    // getchar();
    // getchar();
	return 0;
}
