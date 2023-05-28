#include <iostream>
#include <cstdio>
using namespace std;
int a[5005];
int q[5005];
int have[1000005];

signed main() {
	freopen("noodles.in", "r", stdin);
	freopen("noodles.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] % m == 0) {
			ans++;
		}
		q[i] = (q[i - 1] + a[i]) % m;
		have[q[i]]++;
	}
	for (int i = 0; i < m; i++) {
		ans += ((have[i] * (have[i] )) / 2);
	}
	cout << ans;
	return 0;
}

