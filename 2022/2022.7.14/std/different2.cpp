#include <bits/stdc++.h>

const int N = 2e5 + 5, Max = 2e6 + 5;

using namespace std;

int n, m, l, r, a;
int f[N][20];
int Log[N], last[Max], pre[N];

inline int read() {
    int n = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = (~f + 1);
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        n = (n << 3) + (n << 1) + (c ^ 48);
        c = getchar();
    }
    return n * f;
}

inline void prepare() {
    Log[0] = -1;
    for (int i = 1; i <= n; i++) Log[i] = Log[i >> 1] + 1;
    for (int j = 1; j <= Log[n]; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    return;
}

inline int work(int L, int R) {
    int l = L, r = R, ans = l;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (pre[mid] < L) {
            l = mid + 1;
            ans = mid;
        } else
            r = mid - 1;
    }
    return ans;
}

inline int query(int l, int r) {
    int k = Log[r - l + 1];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
int main() {
	freopen("different.in", "r", stdin);
    freopen("different.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        a = read();
        pre[i] = max(pre[i - 1], last[(int)(a + 1e6)] + 1);
        f[i][0] = i - pre[i] + 1;
        last[(int)(a + 1e6)] = i;
    }
    prepare();
    while (m--) {
        l = read() + 1, r = read() + 1;
        int len = work(l, r), ans = len - l + 1;
        if (len < r)
            ans = max(ans, query(len + 1, r));
        printf("%d\n", ans);
    }
    return 0;
}
