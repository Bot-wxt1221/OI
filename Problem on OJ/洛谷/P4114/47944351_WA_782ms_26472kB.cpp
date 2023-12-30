#include <iostream>
#include <cstdio>
#include <pthread.h>
inline int read();
namespace seg{
  int tree[800005];
  int o[100005];
  void build(int now,int l,int r){
    if(l>r){
      return ;
    }
    if(l==r){
      tree[now]=o[l];
      return ;
    }
    int mid=(l+r)/2;
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
    tree[now]=std::max(tree[now*2],tree[now*2+1]);
    return ;
  }
  int ll;
  void mod(int now,int l,int r){
    if(l>r){
      return ;
    }
    if(l==ll&&ll==r){
      tree[now]=o[ll];
      return ;
    }
    if(r<ll||ll<l){
      return ;
    }
    int mid=(l+r)/2;
    mod(now*2,l,mid);
    mod(now*2+1,mid+1,r);
    tree[now]=std::max(tree[now*2],tree[now*2+1]);
    return ;
  }
  int qql,qqr;
  int query(int now,int l,int r){
    if(l>r){
      return 0;
    }
    if(qqr<l||r<qql){
      return 0;
    }
    if(qql<=l&&r<=qqr){
      return tree[now];
    }
    int mid=(l+r)/2;
    return std::max(query(now*2,l,mid),query(now*2+1,mid+1,r));
  }
};
namespace pro{
  inline int read();
  int fir[100005];
  int nxt[200005];
  int v[200005];
  int w[200005];
  int ori[200005];
  int now;
  int down[100005];
  void add(int x,int y,int z){
    v[++now]=y;
    w[now]=z;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
  }
  int siz[100005];
  int fa[100005][30];
  int dep[100005];
  int bigson[100005];
  int getlca(int x,int y){
    if(dep[x]<dep[y]){
      std::swap(x,y);
    }
    while(dep[x]>dep[y]){
      int i=29;
      for(i=29;i>0;i--){
        if(dep[fa[x][i]]>dep[y]){
          break;
        }
      }
      x=fa[x][i];
    }
    while(x!=y){
      int i=29;
      for(i=29;i>0;i--){
        if(fa[x][i]!=fa[y][i]){
          break;
        }
      }
      x=fa[x][i];
      y=fa[y][i];
    }
    return x;
  }
  void dfs1(int now,int fa){
    dep[now]=dep[fa]+1;
    pro::fa[now][0]=fa;
    for(int i=1;i<30;i++){
      pro::fa[now][i]=pro::fa[pro::fa[now][i-1]][i-1];
    }
    siz[now]=1;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      down[ori[i]]=v[i];
      dfs1(v[i],now);
      if(bigson[now]==0||siz[v[i]]>siz[bigson[now]]){
        bigson[now]=v[i];
      }
      siz[now]+=siz[v[i]];
    }
    return ;
  }
  int top[100005];
  int t2li[100005];
  int dfn;
  void dfs2(int now,int fa,int top){
    pro::top[now]=top;
    t2li[now]=++dfn;
    if(bigson[now]!=0){
      dfs2(bigson[now],now,top);
    }
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa||v[i]==bigson[now]){
        continue;
      }
      dfs2(v[i],now,v[i]);
    }
    return ;
  }
  char temp[50];
  int solve(){
    int n=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
    }
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      int w=read();
      add(x,y,w);
      ori[now]=i;
      add(y,x,w);
      ori[now]=i;
    }
    dfs1(1,1);
    dfs2(1,1,1);
    for(int i=1;i<n;i++){
      seg::o[down[i]]=w[i];
    }
    seg::build(1,1,n);
    while(scanf("%s",temp+1)){
      if(temp[1]=='D'){
        return 0;
      }
      if(temp[1]=='C'){
        int x=read();
        int t=read();
        seg::o[down[x]]=t;
        seg::ll=down[x];
        seg::mod(1,1,n);
      }else{
        int a=read();
        int b=read();
        int lca=getlca(a,b);
        int ans=0;
        while(top[a]!=top[lca]){
          seg::qql=t2li[top[a]];
          seg::qqr=t2li[a];
          ans=std::max(ans,seg::query(1,1,n));
          a=fa[top[a]][0];
        }
        seg::qql=t2li[lca]+1;
        seg::qqr=t2li[a];
        if(seg::qql<=seg::qqr)
          ans=std::max(ans,seg::query(1,1,n));
        while(top[b]!=top[lca]){
          seg::qql=t2li[top[b]];
          seg::qqr=t2li[b];
          ans=std::max(ans,seg::query(1,1,n));
          b=fa[top[b]][0];
        }
        seg::qql=t2li[lca]+1;
        seg::qqr=t2li[b];
        if(seg::qql<=seg::qqr)
          ans=std::max(ans,seg::query(1,1,n));
        printf("%d\n",ans);
      }
    }
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


