/*
����:������f(x)Ϊ x=n ʱ�Ĵ�.f(1)=1.����f(k+1)���ǿ��ǽ� k+1 ���뵽ǰ k����,���� k��ÿ����������,����֪�� k+1ֻ�ܲ��뵽 k����߻��ұ�.
����f(k+1)=2*f(k).����f(n)=2^(n-1).
���� n�ܴ�, ֱ��ģ��ᳬʱ.�ڼ��� 2^x ʱ�ȼ��� k=2^(x div 2).��xΪż��,�� 2^x=k^2,���� 2^x=2*k^2.�ɴ��㷨��Ч����O(n)����O(logn)��
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

