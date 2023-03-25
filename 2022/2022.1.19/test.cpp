#include <cstdio>
#include <iostream>
#define LL long long

#define MAXN 1200000
#define mod 10000007

#define H

using namespace std;

LL N, K;
LL cent[MAXN];
LL high, low;//high / low

LL q_pow(LL a, LL b);
LL C(LL m, LL n);

LL Euler(LL x);

int main()
{
	int n,m;
	cin>>n>>m;
	if(n>m||(m-n)%2==1){
		cout<<0;
		return 0;
	}
	cent[0] = 1;
	for (int i=1; i<=m; i++)
	{
		cent[i] = i * cent[i - 1] % mod;
		
	}
	cout<<C((m-n)/2,m);
	return 0;
}

LL q_pow(LL a, LL b)
{
	LL all = 1LL;
	
	if (b < 0)
	{
		return 1LL;
	}
	
	while (b)
	{
		if (b & 1LL)
		{
			all *= a;
			all %= mod;
		}
		
		a *= a;
		a %= mod;
		b >>= 1;
	}
	
	return all;
}

LL C(LL m, LL n)
{
	if (m > n)
	{
		return 0LL;
	}
	
	LL t = cent[m] * cent[n - m] % mod;
	return cent[n] * q_pow(t, Euler(mod) - 1) % mod;
}

LL Euler(LL x)
{
	LL all = 1LL;
	LL i;
	
	for (i=2; i*i<=x; i++)
	{
		if (x % i == 0)
		{
			x /= i;
			all *= (i - 1);
			while (x % i == 0)
			{
				x /= i;
				all *= i;
			}
		}
	}
	if (x > 1)
	{
		all *= x - 1;
	}
	
	return all;
}
