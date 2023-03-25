#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
void read(int &x) {
    char ch = getchar();
    x = 0;
    int sgn = 1;
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            sgn = -1;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    x *= sgn;
}
int f[1000100][21], n, m;
int main() {
	freopen("range_max.in", "r", stdin);
    freopen("range_max.out", "w", stdout);
    read(n);
    read(m);
    for (int i = 1; i <= n; i++) read(f[i][0]);
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++) f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    while (m--) {
        int l, r;
        read(l);
        read(r);
        int k = log2(r + 1 - l);
        int ans = max(f[l][k], f[r - (1 << k) + 1][k]);
        printf("%d\n", ans);
    }
    return 0;
}
