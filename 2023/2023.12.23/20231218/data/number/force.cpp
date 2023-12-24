#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll s,n,m;
		scanf("%lld%lld%lld",&s,&n,&m);
		while(n--)s=(s+h(s))%m;
		printf("%lld\n",s);
	}
	return 0;
}
