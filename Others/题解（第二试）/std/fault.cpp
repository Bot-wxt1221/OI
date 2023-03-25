#include <cstdio>

#define LL long long

#define H

using namespace std;

void dfs(LL n, LL k);

int main()
{
	LL n;
	LL k;//ͳһ����long long���ͣ���ֹ��� 
	
	#ifdef H
	freopen("fault.in", "r", stdin);
	freopen("fault.out", "w", stdout);
	#endif
	
	scanf("%lld %lld", &n, &k);
	dfs(n, k);//����ת������ 
	
	#ifdef H
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}

void dfs(LL n, LL k)
{
	if (n == 0ll)//��ֹ������n��ת������ 
	{
		return;
	}
	LL rest = n % k;
	n /= k;//��kȡ�� 
	if (rest < 0ll)//��������restΪ��������� 
	{
		rest -= k;
		n += 1;
	}
	dfs(n, k);
	if (rest > 9ll)//���������⣬�ж������дӢ����ĸ�������� 
	{
		putchar('A' + rest - 10ll);
	}
	else
	{
		putchar(rest + '0');
	}
	
	return;
}
