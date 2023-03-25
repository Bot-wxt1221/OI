#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
int n, m, k[MAX_N], kk[MAX_N * MAX_N];

void solve() {
    // 枚举k[c]+k[d]的和
    for (int c = 0; c < n; c++)
		for (int d = 0; d < n; d++) 
	   		kk[c * n + d] = k[c] + k[d];
    // 为了执行二分查找需要先排序
	sort(kk, kk + n * n);
	bool f = false;
	for (int a = 0; a < n; a++)
   		for (int b = 0; b < n; b++)
       		// 将最内侧的两个循环替换成二分搜索
       		if (binary_search(kk, kk + n * n, m - k[a] - k[b])) f = true;
	if (f) printf("Yes\n");
	else printf("No\n");
}

int main() {
	freopen("draw_lots.in", "r", stdin);
	freopen("draw_lots.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) 
			scanf("%d", &k[i]);
		solve();
	}
	
	return 0;
}
