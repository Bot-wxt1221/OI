#include <iostream>
#include <cstdio>
#define is(c) isdigit(c)
const int N = 2e5 + 10;
const int M = 1e6 + 10;
const int LOGN = 19;
using namespace std;

int n, m, ans, las[M << 1], st[N], len[N], log[N], f[N][LOGN];

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

int find(int L, int R) {
    if (st[L] == L)
        return L;
    if (st[R] < L)
        return R + 1;
    int l = L, r = R;
    while (l <= r) {
        int mid = l + r >> 1;
        if (st[mid] < L)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int query(int x, int y) {
    int k = log[y - x + 1];
    return max(f[x][k], f[y - (1 << k) + 1][k]);
}

int main() {
	freopen("different.in", "r", stdin);
    freopen("different.out", "w", stdout);
    read(n);
    read(m);
    int a;
    for (int i = 1; i <= n; i++) {
        read(a);
        st[i] = max(st[i - 1], las[a + M] + 1);
        len[i] = i - st[i] + 1;
        las[a + M] = i;
    }
    log[0] = -1;
    for (int i = 1; i <= n; i++) log[i] = log[i >> 1] + 1;
    for (int i = 1; i <= n; i++) f[i][0] = len[i];
    for (int j = 1; j <= LOGN; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
    while (m--) {
        int L, R;
        read(L);
        read(R);
        L++;
        R++;
        int mid = find(L, R);
        ans = 0;
        if (mid > L)
            ans = max(ans, mid - L);
        if (mid <= R)
            ans = max(ans, query(mid, R));
        printf("%d\n", ans);
    }
    return 0;
}
