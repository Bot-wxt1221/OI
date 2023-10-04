#include <iostream>
#include <cstdio>
#define is(c) isdigit(c)
const int N = 1e5 + 10;
const int LOGN = 18;
using namespace std;

int n, m, k, a[N], log[N], f[N][LOGN], g[N][LOGN];

void read(int &s) {
    s = 0;
    bool f = false;
    char c = getchar();
    while (!is(c)) {
        if (c == '-')
            f = true;
        c = getchar();
    }
    while (is(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    if (f)
        s = -s;
    return;
}

int main() {
	freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    read(n);
    read(k);
    m = n - k + 1;
    for (int i = 1; i <= n; i++) read(a[i]);
    log[0] = -1;
    for (int i = 1; i <= n; i++) log[i] = log[i >> 1] + 1;
    for (int i = 1; i <= n; i++) f[i][0] = g[i][0] = a[i];
    for (int j = 1; j <= LOGN; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
            g[i][j] = min(g[i][j - 1], g[i + (1 << j - 1)][j - 1]);
        }
    for (int i = 1; i <= m; i++) {
        int x = i, y = i + k - 1;
        int s = log[y - x + 1];
        printf("%d ", max(f[x][s], f[y - (1 << s) + 1][s]));
        printf("%d\n", min(g[x][s], g[y - (1 << s) + 1][s]));
    }
    return 0;
}
