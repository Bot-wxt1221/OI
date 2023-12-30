#include <iostream>
#include <cstdio>
#define int long long
#define mod (998244353ll)
inline int read();
int fir[500005];
int nxt[1000005];
int v[1000005];
int f[500005];
int g[500005][64][2];
int x[500005];
int now=0;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  for(int i=0;i<64;i++){
    g[now][i][(x[now]>>i)&1ll]=1;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    for(int ii=0;ii<64;ii++){
      int t0=g[now][ii][0];
      int t1=g[now][ii][1];
      g[now][ii][0]=((((t0*(g[v[i]][ii][0]+f[v[i]])%mod))%mod)+(t1*g[v[i]][ii][1])%mod)%mod;
      g[now][ii][1]=((((t1*(g[v[i]][ii][0]+f[v[i]])%mod))%mod)+(t0*g[v[i]][ii][1])%mod)%mod;
    }
  }
  for(int i=0;i<64;i++){
    f[now]+=((1ll<<i)%mod*g[now][i][1])%mod;
    f[now]%=mod;
  }
  return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    x[i]=read();
    fir[i]=-1;
  }
  for(int i=2;i<=n;i++){
    int temp=read();
    add(i,temp);
    add(temp,i);
  }
  dfs(1,1);
  printf("%lld",f[1]);
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


