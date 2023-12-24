#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,k;
ll d[100005],h[100005],ans;
int main()
{
	freopen("roadblock.in", "r", stdin);
	freopen("roadblock.out", "w", stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&d[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
	for(int i=n+1;i>=1;i--)d[i]-=d[i-1],h[i]-=h[i-1];
	ll a=0,b=0;
	for(int i=1;i<=n+1;i++)
	{
		if(d[i]<-k)a+=-k-d[i];
		else if(d[i]>k)b+=d[i]-k;
		ans+=max(0ll,h[i]);
	}
	printf("%lld\n",ans+max(a,b));
	return 0;
}
