#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
int n, m, k[MAX_N], kk[MAX_N * MAX_N];

void solve() {
    // ö��k[c]+k[d]�ĺ�
    for (int c = 0; c < n; c++)
		for (int d = 0; d < n; d++) 
	   		kk[c * n + d] = k[c] + k[d];
    // Ϊ��ִ�ж��ֲ�����Ҫ������
	sort(kk, kk + n * n);
	bool f = false;
	for (int a = 0; a < n; a++)
   		for (int b = 0; b < n; b++)
       		// �����ڲ������ѭ���滻�ɶ�������
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
