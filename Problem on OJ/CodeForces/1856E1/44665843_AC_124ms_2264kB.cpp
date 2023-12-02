#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int fir[50005];
int nxt[50005];
int v[50005];
int now=0;
int siz[50005];
int dp[50005];
void add(int xx,int yy){
    v[++now]=yy;
    nxt[now]=fir[xx];
    fir[xx]=now;
    return ;
}
void dfs(int now,int fa){
    siz[now]=1;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa){
            continue;
        }
        dfs(v[i],now);
        siz[now]+=siz[v[i]];
    }
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=2;i<=n;i++){
        int temp=read();
        add(i,temp);
        add(temp,i);
    }
    dfs(1,1);
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(dp,0,sizeof(dp));
        for(int jj=fir[i];jj!=-1;jj=nxt[jj]){
            int j=v[jj];
            for(int now=n;now>=siz[j];now--){
                dp[now]=std::max(dp[now],dp[now-siz[j]]+siz[j]);
            }
        }
        int _max=dp[siz[i]/2];
        ans+=(_max)*(siz[i]-_max-1);
    }
    printf("%lld",ans);
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


