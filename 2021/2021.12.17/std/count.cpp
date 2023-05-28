#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long much[1000005];
int s[1000005];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int a,n,k;long long ans=0;
	much[0]=1LL;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		s[i]=s[i-1]+a;
		s[i]%=k;
		ans+=much[s[i]];
		much[s[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}
