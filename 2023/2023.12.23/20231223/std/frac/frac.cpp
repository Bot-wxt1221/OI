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

const int N=25;
int t,a,b,n,m,A[N],B[N],nm[10];

signed main()
{
	freopen("frac.in","r",stdin);
	freopen("frac.out","w",stdout);
	t=read();
	while(t--)
	{
		a=read();b=read();
		int aa=a,bb=b;n=0;m=0;
		while(aa)
		{
			A[++n]=aa%10;
			aa/=10;
		}
		while(bb)
		{
			B[++m]=bb%10;
			bb/=10;
		}
		int ans1=a,ans2=b;
		for(int i=1;i<(1<<n);++i)
		{
			int tmp=0;
			for(int j=n-1;j>=0;--j)
				if((i>>j)&1)
					tmp=tmp*10+A[j+1];
				else nm[A[j+1]]++;
			__int128 qwq=tmp;qwq*=b;
			if(!tmp||qwq%a!=0)
			{
				for(int j=0;j<10;++j)
					nm[j]=0;
				continue;
			}
			qwq/=a;int nd=qwq,ND=nd,fl=1;
			for(int j=1;j<=m;++j)
				if(B[j]==nd%10)
					nd/=10;
				else nm[B[j]]--;
			for(int j=0;j<10;++j)
				if(nm[j]) fl=0,nm[j]=0;
			if(nd||!fl) continue;
			if(ans1==-1||tmp<ans1)
				ans1=tmp,ans2=ND;
		}
		write(ans1);putchar(' ');write(ans2);puts("");
	}
	return 0;
}
