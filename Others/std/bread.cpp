#include <cstdio>
using namespace std;

int n, k;

int main()
{
	freopen("bread.in", "r", stdin);
	freopen("bread.out", "w", stdout);
	scanf("%d%d", &n, &k);
	if (k >= n) puts("2"); else
		if (2 * n % k) printf("%d\n", 2 * n / k + 1);
			else printf("%d\n", 2 * n / k);
	return 0;
}
