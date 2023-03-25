#include <cstdio>

#define LL long long

#define H

using namespace std;

void dfs(LL n, LL k);

int main()
{
	LL n;
	LL k;//统一开成long long类型，防止溢出 
	
	#ifdef H
	freopen("fault.in", "r", stdin);
	freopen("fault.out", "w", stdout);
	#endif
	
	scanf("%lld %lld", &n, &k);
	dfs(n, k);//深搜转换进制 
	
	#ifdef H
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}

void dfs(LL n, LL k)
{
	if (n == 0ll)//终止条件：n被转换完了 
	{
		return;
	}
	LL rest = n % k;
	n /= k;//除k取余 
	if (rest < 0ll)//处理余数rest为负数的情况 
	{
		rest -= k;
		n += 1;
	}
	dfs(n, k);
	if (rest > 9ll)//解决输出问题，判断输出大写英文字母还是数字 
	{
		putchar('A' + rest - 10ll);
	}
	else
	{
		putchar(rest + '0');
	}
	
	return;
}
