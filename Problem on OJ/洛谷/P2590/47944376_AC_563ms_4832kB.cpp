#include <iostream>
#include <cstdio>
inline int read();
namespace pro{
  inline int read();
  int lowbit(int x){
    return (x)&(-x);
  }
  int n;
  int seq[30005];
  class SEG{
    public:
      int treemax[120005];
      int treesum[120005];
      void build(int now,int l,int r){
        if(l>r){
          treemax[now]=-0x3f3f3f3f;
          treesum[now]=0;
          return  ;
        }
        if(l==r){
          treemax[now]=seq[l];
          treesum[now]=seq[r];
          return ;
        }
        int mid=(l+r)/2;
        build(now*2,l,mid);
        build(now*2+1,mid+1,r);
        treemax[now]=std::max(treemax[now*2],treemax[now*2+1]);
        treesum[now]=treesum[now*2]+treesum[now*2+1];
        return ;
      }
      int ql,qr,ans;
      void querymax(int now,int l,int r){
        if(l>r){
          return ;
        }
        if(ql<=l&&r<=qr){
          ans=std::max(ans,treemax[now]);
          return ;
        }
        if(r<ql||qr<l){
          return ;
        }
        int mid=(l+r)/2;
        querymax(now*2,l,mid);
        querymax(now*2+1,mid+1,r);
        return ;
      }
      void querysum(int now,int l,int r){
        if(l>r){
          return ;
        }
        if(ql<=l&&r<=qr){
          ans+=treesum[now];
          return ;
        }
        if(r<ql||qr<l){
          return ;
        }
        int mid=(l+r)/2;
        querysum(now*2,l,mid);
        querysum(now*2+1,mid+1,r);
      }
      int mpos,mop;
      void mod(int now,int l,int r){
        if(l>r){
          return ;
        }
        if(l==mpos&&mpos==r){
          treesum[now]=mop;
          treemax[now]=mop;
          return ;
        }
        if(r<mpos||mpos<l){
          return ;
        }
        int mid=(l+r)/2;
        mod(now*2,l,mid);
        mod(now*2+1,mid+1,r);
        treesum[now]=treesum[now*2]+treesum[now*2+1];
        treemax[now]=std::max(treemax[now*2],treemax[now*2+1]);
        return ;
      }
  }seg;
  int fir[30005];
  char op[20];
  int nxt[60005];
  int v[60005];
  int w[30005];
  int now=0;
  int siz[30005];
  int bigson[30005];
  int top[30005];
  int dep[30005];
  int dfn[30005];
  int num;
  int id[30005];
  int ffa[30005];
  void dfs1(int now,int fa){
    ffa[now]=fa;
    dep[now]=dep[fa]+1;
    siz[now]=1;
    int maxsiz=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      dfs1(v[i],now);
      siz[now]+=siz[v[i]];
      if(siz[v[i]]>maxsiz){
        maxsiz=siz[v[i]];
        bigson[now]=v[i];
      }
    }
    return ;
  }
  void dfs2(int now,int fa){
    id[now]=++num;
    dfn[num]=now;
    if(bigson[now]==0){
      return ;
    }
    top[bigson[now]]=top[now];
    dfs2(bigson[now],now);
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      if(v[i]==bigson[now]){
        continue;
      }
      top[v[i]]=v[i];
      dfs2(v[i],now);
    }
    return ;
  }
  void add(int x,int y){
    v[++now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
  }
  int solve(){
    n=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
    }
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      add(x,y);
      add(y,x);
    }
    dfs1(1,1);
    top[1]=1;
    dfs2(1,1);
    for(int i=1;i<=n;i++){
      seq[id[i]]=read();
    }
    seg.build(1,1,n);
    int q=read();
    for(int i=1;i<=q;i++){
      scanf("%s",op+1);
      int u=read();
      int v=read();
      if(op[1]=='C'){
        seg.mpos=id[u];
        seq[id[u]]=v;
        seg.mop=v;
        seg.mod(1,1,n);
      }else if(op[2]=='M'){
        int ans=-0x3f3f3f3f;
        while(top[u]!=top[v]){
          if(dep[top[u]]<dep[top[v]]){
            std::swap(u,v);
          }
          seg.ql=id[top[u]];
          seg.qr=id[u];
          seg.ans=-0x3f3f3f3f;
          seg.querymax(1,1,n);
          ans=std::max(ans,seg.ans);
          u=ffa[top[u]];
        }
        if(dep[u]<dep[v]){
          std::swap(u,v);
        }
        seg.ql=id[v];
        seg.qr=id[u];
        seg.ans=-0x3f3f3f3f;
        seg.querymax(1,1,n);
        ans=std::max(ans,seg.ans);
        printf("%d\n",ans);
      }else{
        int ans=0;
        while(top[u]!=top[v]){
          if(dep[top[u]]<dep[top[v]]){
            std::swap(u,v);
          }
          seg.ql=id[top[u]];
          seg.qr=id[u];
          seg.ans=0;
          seg.querysum(1,1,n);
          ans+=seg.ans;
          u=ffa[top[u]];
        }
        if(dep[u]<dep[v]){
          std::swap(u,v);
        }
        seg.ql=id[v];
        seg.qr=id[u];
        seg.ans=0;
        seg.querysum(1,1,n);
        ans+=seg.ans;
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


