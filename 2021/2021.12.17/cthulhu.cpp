#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("cthulhu.in","r",stdin);
	freopen("cthulhu.out","w",stdout);
	int T;
	long long n,s,top,ans,cnt=0,numof2,m1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		m1=1;numof2=0;
		for (int i=2;i<=sqrt(n);i++)
		{
			cnt=0;
			if (n%i==0)
			{
				while(n%i==0)
					n/=i,cnt++;
			}
			cnt*=2;
			if (i==2) numof2=cnt;
			else m1*=(cnt+1);
		}
		if (n==2) numof2+=2;
		else if (n>1) m1*=3;
		ans=(numof2-1)*m1;
		if (numof2==0) ans=m1;
		printf("%lld ",ans/2);
	}
	return 0;
}
