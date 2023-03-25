#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
long long qpow(long long a,long long b)
{
	long long ca=a;
	long long ans=1;
	while (b>0)
	{
		if (b&1) ans*=ca;
		ca=ca*ca;
		ans%=7;
		ca%=7;
		b=b>>1;
	}
	return ans%7;
}
int main()
{
	freopen("week.in","r",stdin);
	freopen("week.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	int days=qpow(a,b);
	days+=7;
	days%=7;
	if (days==0) days=7;
	cout<<days;
	return 0;
}
