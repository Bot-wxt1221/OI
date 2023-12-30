#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int tree[1000005];
int tree2[1000005];
int n,p,m,r;
int lowbit(int now) {
    return now & (-now);
}
void add(int i, int now) {
    int temp = i;

    while (i <= n) {
        tree[i] += now;
        tree2[i] += (now * temp);
        i += lowbit(i);
    }

    return ;
}
void add_two(int l, int r, int now) {
    add(r + 1, -now);
    add(l, now);
    return ;
}
int que(int l) {
    int temp = l;
    int ans = 0;

    while (l > 0) {
        ans -= (tree2[l]);
        ans += ((temp + 1) * tree[l]);
        l -= lowbit(l);
    }

    return ans;
}
int que_two(int l, int r) {
    return ((que(r) - que(l - 1)));
}
int fir[100005];
int nxt[200005];
int v[200005];
int w[100005];
int now=0;
void add1(int uu,int vv){
    now++;
    v[now]=vv;
    nxt[now]=fir[uu];
    fir[uu]=now;
    return ;
}
int dep[100005];
int fa[100005];
int siz[100005];
int bson[100005];
void dfs1(int now,int fa){
    siz[now]=1;
    dep[now]=dep[fa]+1;
    ::fa[now]=fa;
    bson[now]=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa){
            continue;
        }
        dfs1(v[i],now);
        siz[now]+=siz[v[i]];
        if(siz[v[i]]>siz[bson[now]]){
            bson[now]=v[i];
        }
    }
    return ;
}
int id[100005];
int cnt=0;
int top[100005];
void dfs2(int now,int topf){
    id[now]=++cnt;
    add_two(cnt,cnt,w[now]);
    top[now]=topf;
    if(bson[now]==0){
        return ;
    }
    dfs2(bson[now],topf);
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa[now]||v[i]==bson[now]){
            continue;
        }
        dfs2(v[i],v[i]);
    }
    return ;
}
int query1(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]){
            std::swap(x,y);
        }
        ans+=que_two(id[top[x]],id[x]);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]){
        std::swap(x,y);
    }
    ans+=que_two(id[x],id[y]);
    return ans;
}
void add11(int x,int y,int z){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]){
            std::swap(x,y);
        }
        add_two(id[top[x]],id[x],z);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]){
        std::swap(x,y);
    }
    add_two(id[x],id[y],z);
    return ;
}
int query2(int x){
    return que_two(id[x],id[x]+siz[x]-1);
}
void add12(int x,int z){
    add_two(id[x],id[x]+siz[x]-1,z);
    return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    n=read();
    
    for(int i=1;i<=n;i++){
        fir[i]=-1;
        w[i]=0;
    }
    for(int i=1;i<=n-1;i++){
        int x,y;
        x=read()+1;
        y=read()+1;
        add1(x,y);
        add1(y,x);
    }
    dfs1(1,1);
    dfs2(1,1);
  int m=read();
    for(int i=1;i<=m;i++){
        char op;
        std::cin>>op;
        switch(op){
            case 'A':{
                int x,y,z;
                x=read()+1;
                y=read()+1;
                z=read();
                add11(x,y,z);
                break;
            }
            case 'Q':{
                int x=read()+1;
                printf("%lld\n",query2(x));
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