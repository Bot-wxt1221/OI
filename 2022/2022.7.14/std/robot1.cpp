#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010, lgmax = 18;
int f[maxn][lgmax], g[maxn][lgmax], lg[maxn], n, k;
int main() {
	freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i][0]);
        g[i][0] = f[i][0];
    }
    lg[0] = -1;
    for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    for (int j = 1; j <= lg[k] + 1; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            g[n + 1][j - 1] = INT_MAX;
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
            g[i][j] = min(g[i][j - 1], g[i + (1 << j - 1)][j - 1]);
        }
    }
    n = n - k + 1;
    int s = lg[k];
    for (int i = 1; i <= n; i++) {
        int x = i, y = i + k - 1;
        printf("%d %d\n", max(f[x][s], f[y - (1 << s) + 1][s]), min(g[x][s], g[y - (1 << s) + 1][s]));
    }
}
