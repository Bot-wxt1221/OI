#include <bits/stdc++.h>

using namespace std;
int n, a[110], b[110];

int main(int argc, char const *argv[]) {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) a[i] = a[i] * a[i - 1] + 1, sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, greater<int>());
    for (int i = 2; i <= n; i++) b[i] = b[i] * b[i - 1] + 1;
    cout << a[n] - b[n] << endl;
}
