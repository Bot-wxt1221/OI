#include<iostream>
#include<cstdio>
#include<cstring>
#include <cmath>
using namespace std;
int T, n, m, p[110][110], f[110][10010];

int main() {
	freopen("souvenir.in", "r", stdin);
	freopen("souvenir.out", "w", stdout);
	scanf("%d%d%d", &T, &n, &m);
	for (int i = 1; i <= T; ++i) for (int j = 1; j <= n; ++j) scanf("%d", &p[i][j]);
	// f[i][j]:�滮����i����Ʒ�����ﻹʣjԪǮ���ڶ������Ʒ��������������
	for (int k = 1; k < T; ++k) {
		for (int i = 0; i <= 10000; ++i) m = max(m, f[n][i]);
		memset(f, 0xcf, sizeof(f));
		f[0][m] = m; // �߽�
		for (int i = 1; i <= n; ++i) {
			for (int j = m; j >= 0; --j)
				if (j <= m - p[k][i]) f[i][j] = max(f[i-1][j], f[i][j + p[k][i]] - p[k][i] + p[k+1][i]); //ȡ��ȡ
				else f[i][j] = f[i-1][j]; // ��ȡ
		}
	}
	for (int i = 0; i <= 10000; ++i) m = max(m, f[n][i]);
	printf("%d\n", m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
