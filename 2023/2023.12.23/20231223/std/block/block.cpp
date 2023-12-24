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

const int N=205,M=2e5+5,MOD=1e9+7;
int n,m,bel[M],ne[M*2],f[N][M],sm[N][M],vis[M*2],tg[N][M];
char s[M],t[M*2],str[M];

struct Seg
{
    int l,r;
    inline int len()
	{
		return r-l+1;
	}
}a[N];

struct Manacher
{
    char t[M*2+10];
    int lens,lent,mx,p[M*2+10];
    void init(char *str,int len)
    {
        lent=0;lens=len;t[0]='$';
        for(int i=0;i<lens;++i)
            t[++lent]='#',t[++lent]=str[i];
        t[++lent]='#';t[lent+1]='&';
        int id=mx=0;
        for(int i=1;i<=lent;++i)
		{
            if(mx>=i) p[i]=min(mx-i+1,p[id*2-i]);
            else p[i]=1;
            while(t[p[i]+i]==t[i-p[i]]) p[i]++;
            if(p[i]+i-1>mx) mx=p[i]+i-1,id=i;
        }
    }
    inline bool check(int l,int r)
    {
        l++;r++;
        return p[l+r]-1>=r-l+1;
    }
}mana;

void query(int x,int y)
{
    int cnt=0;
    if(x<y)
    {
        for(int i=a[x].r;i>=a[x].l;--i)
			t[++cnt]=s[i],vis[cnt]=0;
        for(int i=a[y].l;i<=a[y].r;++i)
			t[++cnt]=s[i],vis[cnt]=0;
        ne[1]=0;vis[a[x].len()]=1;
        for(int i=2,j=0;i<=cnt;++i)
        {
            while(j&&t[i]!=t[j+1]) j=ne[j];
            if(t[i]==t[j+1]) j++;
            ne[i]=j;
            if(vis[ne[i]])
            {
                vis[i]=1;
                if(i-2*a[x].len()>=0)
					tg[x][a[y].l+i-2*a[x].len()-1]=1;
            }
        }
        for(int i=cnt;i;i=ne[i])
        {
            if(i<a[x].len()&&i<=a[y].len())
				tg[x][a[y].r-i]=1;
        }
        tg[x][a[y].r]=1;
    }
    else
    {
        for(int i=a[x].l;i<=a[x].r;++i)
			t[++cnt]=s[i],vis[cnt]=0;
        for(int i=a[y].r;i>=a[y].l;--i)
			t[++cnt]=s[i],vis[cnt]=0;
        ne[1]=0;vis[a[x].len()]=1;
        for(int i=2,j=0;i<=cnt;++i)
        {
            while(j&&t[i]!=t[j+1]) j=ne[j];
            if(t[i]==t[j+1]) j++;
            ne[i]=j;
            if(vis[ne[i]])
            {
                vis[i]=1;
                if(i-2*a[x].len()>=0)
					tg[x][a[y].l+(a[y].len()-i+2*a[x].len())]=1;
            }
        }
        for(int i=cnt;i;i=ne[i])
            if(i<a[x].len()&&i<=a[y].len())
				tg[x][a[y].l+i]=1;
        tg[x][a[y].l]=1;
    }
}

int Mod(int x)
{
	return x>=MOD?x-MOD:x;
}

signed main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
    n=read();
    int L=1,R;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str+1);
        R=L+strlen(str+1)-1;
        for(int j=L;j<=R;++j)
        	s[j]=str[j-L+1],bel[j]=i;
        a[i].l=L;a[i].r=R;L=R+2;
    }
    m=R;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(j!=i) query(i,j);
    mana.init(s,m+1);
    for(int i=1;i<=n;++i)
    {
    	sm[n+1][a[i].l]=sm[0][a[i].r]=1;
		f[n+1][a[i].l]=f[0][a[i].r]=1;
	}
    for(int i=n-1;i>=1;--i)
        for(int l=1;l+i<=n;++l)
        {
            int r=l+i;
            for(int j=a[r].l-1;j<=a[r].r;++j)
            {
                if(!tg[l][j]) f[l][j]=0;
                else if(a[r].r-j>=a[l].len())
					f[l][j]=sm[l-1][j+a[l].len()];
                else f[l][j]=sm[r+1][a[l].r-(a[r].r-j)+1];
                sm[l][j]=Mod(f[l][j]+sm[l-1][j]);
            }
            for(int j=a[l].l;j<=a[l].r+1;++j)
            {
                if(!tg[r][j]) f[r][j]=0;
                else if(j-a[l].l>=a[r].len())
					f[r][j]=sm[r+1][j-a[r].len()];
                else f[r][j]=sm[l-1][a[r].l+(j-a[l].l)-1];
                sm[r][j]=Mod(f[r][j]+sm[r+1][j]);
            }
        }
    int res=0;
    for(int l=1;l<=n;++l)
        for(int r=l+1;r<=n;++r)
        {
            res=Mod(res+f[l][a[r].l-1]);
            for(int j=a[r].l;j<=a[r].r;++j)
                if(mana.check(a[r].l,j))
					res=Mod(res+f[l][j]);
            for(int j=a[l].l+1;j<=a[l].r;++j)
                if(mana.check(j,a[l].r))
					res=Mod(res+f[r][j]);
        }
    for(int i=1;i<=n;i++)
        if(mana.check(a[i].l,a[i].r))
            res=Mod(res+1);
    write(res);
    return 0;
}
