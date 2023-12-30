#include <iostream>
#include <cstdio>
inline int read();
namespace pro{
  inline int read();
  int fir[300005];
  int nxt[600005];
  int v[600005];
  int now;
  void add(int x,int y){
    v[++now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
  }
  int siz[300005];
  int _max[300005];
  int sum[300005];
  void dfs(int now,int fa){
    siz[now]=1;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      dfs(v[i],now);
      siz[now]+=siz[v[i]];
      _max[now]=std::max(_max[now],siz[v[i]]);
    }
  }
  int solve(){
    int n=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
    }
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      add(x,y);
      add(y,x);
    }
    dfs(1,1);
    printf("%d",n-(_max[1]));
    return 0; 
  }
};
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	return pro::solve();
}
inline int pro::read(){
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


