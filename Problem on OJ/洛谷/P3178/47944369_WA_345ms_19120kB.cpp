#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int ww[100005];
int fir[100005];
int nxt[200005];
int v[200005];
int n;
int tree[1000005];
int tree2[1000005];
int lowbit(int now) {
    return now & (-now);
}
void add1(int i, int now) {
    int temp = i;

    while (i <= n) {
        tree[i] += now;
        tree2[i] += now * temp;
        i += lowbit(i);
    }

    return ;
}
void add_two(int l, int r, int now) {
    add1(r + 1, -now);
    add1(l, now);
    return ;
}
int que(int l) {
    int temp = l;
    int ans = 0;

    while (l > 0) {
        ans -= tree2[l];
        ans += (temp + 1) * tree[l];
        l -= lowbit(l);
    }

    return ans;
}
int que_two(int l, int r) {
    return que(r) - que(l - 1);
}
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int bigson[100005];
int siz[100005];
int fa[100005];
void dfs1(int now,int faa){
  fa[now]=faa;
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==faa){
      continue;
    }
    dfs1(v[i],now);
    siz[now]+=siz[v[i]];
    if(bigson[now]==0||siz[v[i]]>siz[bigson[now]]){
      bigson[now]=v[i];
    }
  }
  return ;
}
int dfn;
int tr2l[100005];
int tr2le[100005];
int l2tr[100005];
int top[100005];
void dfs2(int now,int faa){
  dfn++;
  add_two(dfn,dfn,ww[now]);
  tr2l[now]=dfn;
  l2tr[dfn]=now;
  if(bigson[now]==0){
    return ;
  }
  top[bigson[now]]=top[now];
  dfs2(bigson[now],now);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==faa||v[i]==bigson[now]){
      continue;
    }
    top[v[i]]=v[i];
    dfs2(v[i],now);
  }
  tr2le[now]=dfn;
  return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    ww[i]=read();
  }
  for(int i=1;i<n;i++){
    int u=read();
    int v=read();
    add(u,v);
    add(v,u);
  }
  dfs1(1,1);
  top[1]=1;
  dfs2(1,1);
  for(int i=1;i<=m;i++){
    int op=read();
    switch (op) {
      case 1:{
        int x=read();
        int a=read();
        add_two(tr2l[x],tr2l[x],a);
        break;
      }
      case 2:{
        int x=read();
        int a=read();
        add_two(tr2l[x],tr2le[x],a);
        break;
      }
      case 3:{
        int ans=0;
        int x=read();
        while(x!=1){
          ans+=que_two(tr2l[top[x]],tr2l[x]);
          x=fa[top[x]];
        }
        printf("%d\n",ans);
        break;
      }
    }
  }
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
