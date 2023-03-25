#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e5 + 10, LOGN = 17;
int log[N], f[N][LOGN + 1], g[N][LOGN + 1], a[N];
int n, k;

int main() {
	freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    log[0] = -1;
    for (int i = 1; i <= n; i++) f[i][0] = g[i][0] = a[i], log[i] = log[i >> 1] + 1;
    // for(int i=0;i<=n;i++) { printf("%d\n",log[i]); }

    for (int j = 1, u; j <= LOGN; j++) {
        u = j - 1;
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = max(f[i][u], f[i + (1 << u)][u]), g[i][j] = min(g[i][u], g[i + (1 << u)][u]);
        }
    }

    n = n - k + 1;
    int s = log[k];
    for (int i = 1, x, y; i <= n; i++) {
        x = i, y = i + k - 1;
        printf("%d %d\n", max(f[x][s], f[y - (1 << s) + 1][s]), min(g[x][s], g[y - (1 << s) + 1][s]));
    }

    return 0;
}
