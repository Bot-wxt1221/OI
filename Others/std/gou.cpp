#include <cstdio>
using namespace std;

const int N = 1000010;
int f[N], num[N], p[N], n, ans, t;
bool v[N];

int main()
{
	freopen("gou.in", "r", stdin);
	freopen("gou.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			p[++t] = i; num[i] = 1;
			if (i % 4 == 1) f[i] = 3; else f[i] = 1;
		}
		for(int j = 1; j <= t && i * p[j] <= n; j++)
		{
			v[i * p[j]] = 1;
			if (i % p[j]) f[i * p[j]] = f[i] * f[p[j]], num[i * p[j]] = 1;
			else
			{
				num[i * p[j]] = num[i] + 1;
				if (p[j] % 4 == 1)
					f[i * p[j]] = f[i] / (2 * num[i] + 1) * (2 * num[i] + 3);
					else f[i * p[j]] = f[i];
				break;
			}
		}
	}
	for(int i = 2; i <= n; i++) ans += (f[i] - 1) >> 1;
	printf("%d\n", ans);
	return 0;
}
