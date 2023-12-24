#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll INF=2000000000000000000;
ll f[20][10][10];
int g[20][10][10];
int h(ll x)
{
	int s=0;
	while(x)
	{
		s+=(int)(x%10);
		x/=10;
	}
	return (s+9)%10+1;
}
int nxt[15][105];
ll tot[15][105];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
	{
		int x=j;
		while(x<10)x+=(h(x)+i+9)%10+1,f[1][i][j]++;
		g[1][i][j]=x%10;
	}
	for(int n=2;n<19;n++)
	{
		for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			int cur=j;
			for(int d=0;d<10;d++)
			{
				f[n][i][j]+=f[n-1][(i+d)%10][cur];
				cur=g[n-1][(i+d)%10][cur];
			}
			g[n][i][j]=cur;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll s,n,m;
		scanf("%lld%lld%lld",&s,&n,&m);
		memset(tot,0,sizeof(tot));
		memset(nxt,0,sizeof(nxt));
		for(int d=0;d<min(10ll,m);d++)
		{
			ll s=d;
			while(1)
			{
				if(m-s<20)break;
				int i=1;
				ll ii=10;
				while(s%ii<10&&(s/ii+1)*ii+g[i][h(s/ii)%10][s%10]<m)
					i++,ii*=10;
				i--,ii/=10;
				tot[d][0]+=f[i][h(s/ii)%10][s%10];
				s=(s/ii+1)*ii+g[i][h(s/ii)%10][s%10];
			}
			while(s<m) s+=h(s),tot[d][0]++;
			nxt[d][0]=(int)(s%m);
		}
		for(int i=1;i<=100;i++)
		{
			for(int d=0;d<10;d++)
			{
				tot[d][i]=tot[d][i-1]+tot[nxt[d][i-1]][i-1];
				if(tot[d][i]>INF)tot[d][i]=INF;
				nxt[d][i]=nxt[nxt[d][i-1]][i-1];
			}
		}
		while(1)
		{
			if(n<10)break;
			if(m-s<20)break;
			int i=1;
			ll ii=10;
			while(s%ii<10&&f[i][h(s/ii)%10][s%10]<=n&&(s/ii+1)*ii+g[i][h(s/ii)%10][s%10]<m)
				i++,ii*=10;
			i--,ii/=10;
			n-=f[i][h(s/ii)%10][s%10];
			s=(s/ii+1)*ii+g[i][h(s/ii)%10][s%10];
		}
		while(n>0&&s<m)
		{
			n--;
			s+=h(s);
		}
		if(n==0)printf("%lld\n",s%m);
		else
		{
			s%=m;
			for(int i=100;i>=0;i--)
			{
				if(tot[s][i]<=n)
				{
					n-=tot[s][i];
					s=nxt[s][i];
				}
			}
			while(1)
			{
				if(n<10)break;
				int i=1;
				ll ii=10;
				while(s%ii<10&&f[i][h(s/ii)%10][s%10]<=n)
					i++,ii*=10;
				i--,ii/=10;
				n-=f[i][h(s/ii)%10][s%10];
				s=(s/ii+1)*ii+g[i][h(s/ii)%10][s%10];
			}
			while(n>0)
			{
				n--;
				s+=h(s);
			}
			printf("%lld\n",s%m);
		}
	}
	return 0;
}
