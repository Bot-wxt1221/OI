#include <cstdio>

#define LL long long

#define H

using namespace std;

LL n;
LL all;

int main()
{
	LL l, r, v;
	
	#ifdef H
	freopen("banquet.in", "r", stdin);
	freopen("banquet.out", "w", stdout);
	#endif
	
	scanf("%lld", &n);
	all = 0;
	for (l=1; l<=n; l=r + 1)//枚举区间左端点 
	{
		v = n / l;//计算出n / i的值 
		r = n / v;//计算出右端点的值 
		all += (r - l + 1) * v;//区间求和 
	}
	printf("%lld", all);
	
	#ifdef H
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}
