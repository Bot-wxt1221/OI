/*
分析:我们令f(x)为 x=n 时的答案.f(1)=1.对于f(k+1)我们考虑将 k+1 插入到前 k个中,对于 k的每个单峰排列,容易知道 k+1只能插入到 k的左边或右边.
于是f(k+1)=2*f(k).所以f(n)=2^(n-1).
由于 n很大, 直接模拟会超时.在计算 2^x 时先计算 k=2^(x div 2).若x为偶数,则 2^x=k^2,否则 2^x=2*k^2.由此算法的效率由O(n)降至O(logn)。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int mod = 1234567;

int main(void)
{
	long long n,ans = 1,m = 2;
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	
	cin >> n;
	n--;
	while (n > 0)
	{
		if (n & 1) ans = ans * m % mod;
		m = m * m  % mod;
		n = n >> 1;
	}
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

