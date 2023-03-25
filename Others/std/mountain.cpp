#include <cstdio>
using namespace std;

int n, mx, x, ans;

int main()
{
	freopen("mountain.in", "r", stdin);
	freopen("mountain.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (x > mx) mx = x, ans++;
	}
	printf("%d\n", ans);
	return 0;
} 
