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
	for (l=1; l<=n; l=r + 1)//ö��������˵� 
	{
		v = n / l;//�����n / i��ֵ 
		r = n / v;//������Ҷ˵��ֵ 
		all += (r - l + 1) * v;//������� 
	}
	printf("%lld", all);
	
	#ifdef H
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}
