#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int col[100005];
int fir[100005];
int nxt[200005];
int v[200005];
int now;
int n,k;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dp[1005][1005];
int sum[1005];
void dfs(int now,int fa){
  if(col[now]==0)
    for(int i=1;i<=k;i++){
      dp[now][i]=1;
    }
  else
   dp[now][col[now]]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    for(int j=1;j<=k;j++){
      dp[now][j]*=(((sum[v[i]]-dp[v[i]][j])%mod)+mod)%mod;
      dp[now][j]%=mod;
    }
  }
  for(int i=1;i<=k;i++){
    sum[now]+=dp[now][i];
    sum[now]%=mod;
  }
  return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	#endif
  n=read();
  k=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    col[i]=read();
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  printf("%lld",sum[1]);
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


