#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int q[100010], l = 1, r;
int vis[100010];
struct node {
	int price, t;
} a[100010];

int main() {
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
	int ans = 0;
	int n;
	scanf("%d", &n);
	int stype, sprice, st;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &stype, &sprice, &st);
		if (stype == 0)	{
			ans += sprice;
			a[i].price = sprice;
			a[i].t = st;
			q[++r] = i;
		} else {
			while (l <= r && st - a[ q[l] ].t > 45) ++l;
			int ok = 0;
			for (int j = l; j <= r; ++j)
				if (a[ q[j] ].price >= sprice && vis[j] == 0) {
					vis[j] = 1;
					ok = 1;
					break;
				}
			if (!ok) ans += sprice;
		}
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
