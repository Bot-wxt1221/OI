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

const int N=100005;
int n,m,P,a[N],cnt,bs[20],mod[20];
vector<vector<int>> pw1[20],pw2[20];

inline int mul(int a,int b,int mod)
{
	long long ret=(a>>1)*1ll*(b>>1);
	return ((ret%mod)<<1)|(a&1)|(b&1)|(ret>=mod);
}

inline int pow(int a,int x,int cur)
{
	return mul(pw2[cur][a][x/bs[cur]],pw1[cur][a][x%bs[cur]],mod[cur]);
}

inline int get_phi(int p)
{
	int res=p;
	for(int i=2;i*i<=p;++i)
		if(p%i==0)
		{
			res=res/i*(i-1);
			while(p%i==0)
				p/=i;
		}
	if(p>1) res=res/p*(p-1);
	return res;
}

void init(int p,int cur)
{
	if(p==1) return;
	mod[cur]=p;cnt=cur;
	int b=(int)sqrt(p+0.5);
	int nxt_p=get_phi(p);
	while(b*b<2*nxt_p) b++;
	bs[cur]=b;
	pw1[cur].resize(p);
	pw2[cur].resize(p);
	for(int i=0;i<p;++i)
	{
		pw1[cur][i].resize(b+1);
		int *p1=pw1[cur][i].data();
		pw2[cur][i].resize(b+1);
		int *p2=pw2[cur][i].data();
		p1[0]=p2[0]=1<<1;
		for (int j=1;j<=b;++j)
			p1[j]=mul(p1[j-1],i<<1,p);
		for (int j=1;j<=b;++j)
			p2[j]=mul(p2[j-1],p1[b],p);
	}
	init(nxt_p,cur+1);
}

struct Node
{
	int v[20],tg;
	Node()
	{
		memset(v,0,sizeof(v));tg=0;
	}
	Node(int x,int d)
	{
		v[0]=x;tg=d;
		for(int i=1;i<=cnt;++i)
			v[i]=1;
	}
	inline void push(int x)
	{
		for(int i=cnt;i>=1;--i)
			v[i]=v[i-1];
		v[0]=x;
	}
	inline int query()
	{
		int res=1;
		for(int i=cnt;i>=0;--i)
		{
			int t=pow(v[i]%mod[i],res,i);
			if((t&1)||(v[i]>=mod[i]&&res>0))
				res=(t>>1)+mod[i];
			else res=t>>1;
		}
		return res%P;
	}
};

map<int,Node> ms;

struct Seg
{
	int val[N<<2],tg[N<<2];
	void build(int x,int l,int r)
	{
		tg[x]=-1;
		if(l==r)
		{
			val[x]=a[l];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		val[x]=(val[lc]+val[rc])%P;
	}
	void pushdown(int x,int l,int r)
	{
		if(tg[x]!=-1)
		{
			tg[lc]=tg[rc]=tg[x];
			val[lc]=tg[x]*1ll*(mid-l+1)%P;
			val[rc]=tg[x]*1ll*(r-mid)%P;
			tg[x]=-1;
		}
	}
	void update(int x,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			tg[x]=v;
			val[x]=v*1ll*(r-l+1)%P;
			return;
		}
		pushdown(x,l,r);
		if(L<=mid) update(lc,l,mid,L,R,v);
		if(R>mid) update(rc,mid+1,r,L,R,v);
		val[x]=(val[lc]+val[rc])%P;
	}
	
	int query(int x,int l,int r,int L,int R)
	{
		if (L<=l&&r<=R) return val[x];
		pushdown(x,l,r);int res=0;
		if(L<=mid) res=(res+query(lc,l,mid,L,R))%P;
		if(R>mid) res=(res+query(rc,mid+1,r,L,R))%P;
		return res;
	}	
}sg;

signed main()
{
	freopen("research.in","r",stdin);
	freopen("research.out","w",stdout);
	n=read();m=read();P=read();
	init(P,0);
	for(int i=1;i<=n;++i)
		a[i]=read();
	sg.build(1,1,n);
	for(int i=0;i<=n;++i)
		ms[i]=Node(a[i],cnt);
	for(int i=0;i<m;++i)
	{
		int opt,l,r;
		opt=read();l=read();r=read();
		if(opt==1)
		{
			int x=read();
			if(ms.find(l-1)==ms.end())
				ms.insert(mp(l-1,ms.lower_bound(l)->se));
			ms[l-1].tg=cnt;
			if(ms.find(r)==ms.end())
				ms.insert(mp(r,ms.upper_bound(r)->se));
			ms[r].tg=cnt;
			for(auto it=ms.lower_bound(l);it->fi<r;)
			{
				if(--(it->se.tg)<0) ms.erase(it++);
				else ++it;
			}
			int lst=l;
			for(auto it=ms.lower_bound(l);it!=ms.end()&&it->fi<=r;++it)
			{
				it->se.push(x);
				sg.update(1,1,n,lst,it->fi,it->se.query());
				lst=it->fi+1;
			}
		}
		else printf("%d\n",sg.query(1,1,n,l,r));
	}
	return 0;
}
