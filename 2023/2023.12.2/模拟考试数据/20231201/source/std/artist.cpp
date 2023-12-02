#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,m,q,tot,ans,a[N],fa[N],vis[N],rt[N];
int lc[N*40],rc[N*40],mx[N*40],cnt[N*40];
struct node{int l,r,id;}p[N];
struct SegmentTree{
    #define mid (l+r>>1)
    int bel[N<<2],tag[N<<2];
    inline void pushdown(int k)
    {
        if(!tag[k]) return;
        bel[k<<1]=bel[k<<1|1]=tag[k];
        tag[k<<1]=tag[k<<1|1]=tag[k];
        tag[k]=0;
    }
    void upd(int x,int y,int v,int k=1,int l=1,int r=n)
    {
        if(l>=x&&r<=y) return bel[k]=tag[k]=v,void();
        pushdown(k);
        if(x<=mid) upd(x,y,v,k<<1,l,mid);
        if(mid<y) upd(x,y,v,k<<1|1,mid+1,r);
    }
    int query(int x,int k=1,int l=1,int r=n)
    {
        if(l==r) return bel[k];
        pushdown(k);
        return x<=mid?query(x,k<<1,l,mid):query(x,k<<1|1,mid+1,r);
    }
}T;

inline void pushup(int k) {mx[k]=max(mx[lc[k]],mx[rc[k]]);cnt[k]=cnt[lc[k]]+cnt[rc[k]];}
void update(int &k,int x,int v,int l=1,int r=n)
{
    if(!k) k=++tot;
    if(l==r) {cnt[k]+=v;mx[k]=cnt[k];return;}
    x<=mid?update(lc[k],x,v,l,mid):update(rc[k],x,v,mid+1,r);
    pushup(k);
}

void merge(int &p,int q,int l=1,int r=n)
{
    if(!p||!q) {p=p+q;return;}
    if(l==r) {cnt[p]+=cnt[q];mx[p]=cnt[p];return;}
    merge(lc[p],lc[q],l,mid),merge(rc[p],rc[q],mid+1,r);
    pushup(p);
}

void work(int u,int i)
{
    while(u&&mx[rt[u]]==1&&cnt[rt[u]]==p[u].r-p[u].l+1)
    {
        ans^=i,vis[p[u].id]=1;
        T.upd(p[u].l,p[u].r,fa[u]);
        merge(rt[fa[u]],rt[u]);
        u=fa[u];
    }
}

inline int rd()
{
    int x=0;char c=getchar();
    for(;!isdigit(c);c=getchar());
    for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x;
}

int main()
{
	freopen("artist.in","r",stdin);
	freopen("artist.out","w",stdout);
    n=rd(),m=rd(),q=rd();
    for(int i=1;i<=n;i++) a[i]=rd();
    for(int i=1;i<=m;i++) p[i]={rd(),rd(),i};
    sort(p+1,p+1+m,[&](node a,node b) {return a.r-a.l>b.r-b.l;});
    for(int i=1;i<=m;i++) fa[i]=T.query(p[i].l),T.upd(p[i].l,p[i].r,i);
    for(int i=1;i<=n;i++)
    {
        int u=T.query(i);
        update(rt[u],a[i],1);
        work(u,0);
    }
    for(int i=1;i<=q;i++)
    {
        int x=rd(),y=rd(),u=T.query(x);
        update(rt[u],a[x],-1);a[x]=y;
        update(rt[u],a[x],1);
        work(u,i);
    }
    for(int i=1;i<=m;i++) if(!vis[i]) ans^=m+i;
    cout<<ans<<'\n';
}
