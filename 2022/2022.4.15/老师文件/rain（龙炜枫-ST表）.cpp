#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
#include<ctime>
#define RI register int
using namespace std;
const int maxn=2e5+10,maxlog=20;
int n,ans;
int h[maxn],f[maxn][maxlog+1],lg[maxn],nex[maxn];
inline int read();
inline void print(int x);
inline int query(int l,int r)
{
	return max(f[l][lg[r-l+1]],f[r-(1<<(lg[r-l+1]))+1][lg[r-l+1]]);
}
inline int bfn(int x,int pos,int N)
{
	RI l=pos+1,r=N;
	while(l<r)
	{
		RI mid=(l+r)>>1;
		if(query(l,mid)>=x) r=mid;
		else l=mid+1;
	}
	if(h[l]<x) return 0;
	else return l;
}
inline void init(void)
{
	for(n=1;scanf("%d",&h[n])!=EOF;++n) 
		f[n][0]=h[n];
	--n;	
	for(RI i=1;(1<<i)<=n;++i)
		for(RI j=1;j+(1<<i)-1<=n;++j)
			f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	for(RI i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
	return;
}
int main()
{
	freopen("rain.in","r",stdin);
	freopen("rain.out","w",stdout);
	init();
	for(RI i=2;i<n;++i)	ans+=max(min(query(1,i-1),query(i+1,n))-h[i],0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
inline int read(void)
{
	char putin;bool isneg=false;RI ret=0;
	putin=getchar();
	while((putin>'9' || putin<'0') && putin!='-')
		putin=getchar();
	if(putin=='-')
	{
		isneg=true;
		putin=getchar();
	}
	while(putin>='0' && putin<='9')
	{
		ret=(ret<<3)+(ret<<1)+(putin&15);
		putin=getchar();
	}
	return isneg?-ret:ret;
}
inline void print(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
	return;
}
