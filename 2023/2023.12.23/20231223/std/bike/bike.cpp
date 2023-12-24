#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5,K=24;
int n,m,k,v1,v2,ds[K][K],id[K],p[K],dis[N],vis[N];
double f[1<<19][19];

struct node
{
	int u,w;
	bool operator < (const node &x)const
	{
		return w>x.w;
	}
};

struct Edge
{
	int v,w,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

void dij(int st)
{
	for(int i=1;i<=n;++i)
		dis[i]=INF,vis[i]=0;
	priority_queue<node> qu;
	qu.push((node){id[st],0});dis[id[st]]=0;
	while(!qu.empty())
	{
		int u=qu.top().u;
		qu.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				qu.push((node){v,dis[v]});
			}
		}
	}
	for(int i=0;i<=k+1;++i)
		ds[st][i]=dis[id[i]];
}

signed main()
{
	freopen("bike.in","r",stdin);
	freopen("bike.out","w",stdout);
	n=read();m=read();k=read();
	v1=read();v2=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	for(int i=0;i<k;++i)
	{
		id[i]=read();
		p[i]=read();
	}
	id[k]=1;id[k+1]=n;
	for(int i=0;i<=k+1;++i)
		dij(i);
	for(int i=(1<<k)-1;i>=0;--i)
		for(int j=0;j<k;++j)
			if((i>>j)&1)
			{
				double p1=p[j]/100.0;
				double t1=ds[j][k+1]/(double)v1;
				double t2=ds[j][k+1]/(double)v2;
				f[i][j]=p1*t1+(1-p1)*t2;
				for(int t=0;t<k;++t)
					if(!((i>>t)&1))
						f[i][j]=min(f[i][j],p1*(ds[j][t]/(double)v1+f[i|(1<<t)][t])+(1-p1)*t2);
			}
	double ans=(double)ds[k][k+1]/v1;
	for(int j=0;j<k;++j)
		ans=min(ans,ds[k][j]/(double)v1+f[1<<j][j]);
	printf("%.7lf\n",ans);
	return 0;
}
