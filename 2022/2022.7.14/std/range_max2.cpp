#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
int n, m;
int a[MAXN];
int lg[MAXN];
int f[MAXN][30];
int main() {
	freopen("range_max.in", "r", stdin);
    freopen("range_max.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= n; i++) scanf("%d", &f[i][0]);
    lg[1] = 0;
    lg[2] = 1;
    for (register int i = 3; i < MAXN; i++) lg[i] = lg[i / 2] + 1;
    for (register int j = 1; j <= 21; j++) {
        for (register int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (register int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        int s = lg[y - x + 1];
        printf("%d\n", max(f[x][s], f[y - (1 << s) + 1][s]));
    }
    return 0;
}
