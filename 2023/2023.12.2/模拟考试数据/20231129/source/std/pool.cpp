#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+10;
int n,k,x[N],y[N],h[N];
int stk[N],top,ls[N],rs[N];
ll w[N],s[N],val[N];
vector<ll>v;
int idx,fa[N],rt;
ll dis[N],maxd[N];
void dfs(int u,int l,int r)
{
	if(!u)return;
	val[u]=(s[r]-s[l-1])*(h[u]-max(h[l-1],h[r+1]));
	dfs(ls[u],l,u-1),dfs(rs[u],u+1,r);
	if(dis[ls[u]]>dis[rs[u]])dis[u]=val[u]+dis[ls[u]],v.push_back(dis[rs[u]]);
	else dis[u]=val[u]+dis[rs[u]],v.push_back(dis[ls[u]]);
}
int main()
{
		freopen("pool.in","r",stdin);
		freopen("pool.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	scanf("%d",&k);
	n=(n>>1)-1;
	for(int i=1;i<=n;i++)
		h[i]=y[i<<1],w[i]=x[i<<1|1]-x[i<<1],s[i]=s[i-1]+w[i];
	stk[top=1]=1;
	for(int i=2;i<=n;i++)
	{
		int j=top;
		while(j&&h[stk[j]]>h[i])j--;
		if(j)rs[stk[j]]=i,fa[i]=stk[j];
		if(j<top)ls[i]=stk[j+1],fa[stk[j+1]]=i;
		stk[top=++j]=i;
	}
	rt=stk[1];
	dfs(rt,1,n),v.push_back(dis[rt]);
	sort(v.begin(),v.end()),reverse(v.begin(),v.end());
	ll ans=0;
	for(int i=0;i<min(k,(int)v.size());i++)ans+=v[i];
	printf("%lld",ans);
	return 0;
}
