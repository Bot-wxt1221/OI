#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[100005],pa[100005],ch[100005];
int dep[100005],sze[100005],dfn[100005],top[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node)
{
	dep[node]=dep[pa[node]]+1;
	sze[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs1(to);
		sze[node]+=sze[to];
		if(sze[to]>sze[ch[node]])ch[node]=to;
	}
}
int ind=0;
void dfs2(int node,int t)
{
	dfn[node]=++ind;
	top[node]=t;
	if(ch[node])dfs2(ch[node],t);
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||to==ch[node])continue;
		dfs2(to,to);
	}
}
ll s1[100005],s2[100005];
void _add(int p,ll v)
{
	ll v2=v*p;
	while(p<=n)
	{
		s1[p]+=v;
		s2[p]+=v2;
		p+=p^(p&(p-1));
	}
}
ll _sum(int p)
{
	ll ans=0;
	int cur=p;
	while(cur)
	{
		ans+=s1[cur]*(p+1)-s2[cur];
		cur&=cur-1;
	}
	return ans;
}
void add(int x)
{
	while(x)
	{
		_add(dfn[top[x]],1);
		_add(dfn[x]+1,-1);
		x=pa[top[x]];
	}
}
ll sum(int x)
{
	ll ans=0;
	while(x)
	{
		ans+=_sum(dfn[x])-_sum(dfn[top[x]]-1);
		x=pa[top[x]];
	}
	return ans;
}
ll lastans=0,ans0=0;
int k;
int main()
{
	freopen("history.in", "r", stdin);
	freopen("history.out", "w", stdout);
	scanf("%d%d%d%*d",&n,&m,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1);
	dfs2(1,1);
	int num=0;
	while(m--)
	{
		int op;
		ll x,y;
		scanf("%d%lld",&op,&x);
		if(k)x^=lastans;
		if(op==1)
		{
			scanf("%lld",&y);
			if(k)y^=lastans;
			ans0+=y-dep[x];
			add((int)x);
			num++;
		}
		else printf("%lld\n",lastans=ans0+2*sum((int)x)-1ll*dep[x]*num);
	}
	return 0;
}
