#include <iostream>
#include <stdio.h>
#define N 200005
#define M 1000005
using namespace std;
int n, m, a[N], last[2 * M], log[N], st[N], f[N][20], x, y, t, ans;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int find(int l, int r) {
    if (l == st[l])
        return l;
    if (st[r] < l)
        return r + 1;
    int mid, p = l;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (st[mid] >= p) {
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return l;
}
int query(int l, int r) {
    int p = log[r - l + 1];
    return max(f[l][p], f[r - (1 << p) + 1][p]);
}
int main() {
//	freopen("different.in", "r", stdin);
//    freopen("different.out", "w", stdout);
    log[0] = -1;
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        st[i] = max(st[i - 1], last[a[i] + M] + 1); 
        f[i][0] = i - st[i] + 1;
        log[i] = log[i >> 1] + 1;
        last[a[i] + M] = i;
    }
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
    while (m--) {
        ans = 0;
        x = read() + 1, y = read() + 1;
        t = find(x, y);
        cout<<t<<endl;
        if (t > x)
            ans = t - x;
        if (t <= y) {
            ans = max(ans, query(t, y));
        }
        printf("%d\n", ans);
    }
    return 0;
}
