#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k, a[N], L = 0, R;
bool check(int x) {
    int cnt = 0, now = 0;
    for (int i = 1; i <= n; i++) {
        if (now + a[i] > x)
            now = a[i], cnt++;
        else
            now += a[i];
    }
    return (cnt >= k ? 1 : 0);
}
int main() {
	freopen("divide_b.in", "r", stdin);
	freopen("divide_b.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), L = max(L, a[i]), R += a[i];
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (check(mid))
            L = mid + 1;
        else
            R = mid - 1;
    }
    printf("%d", L);
    return 0;
}
