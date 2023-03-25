#include <iostream>
#include <cstdio>
using namespace std;
int a[1000007], f[1000007][18], ans;  //����Ҫ����һ�� ע����ʮ����һ��
int n, m, l, r, len;
int ind(int x);
int main() {
	freopen("range_max.in", "r", stdin);
    freopen("range_max.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[i][0] = a[i];
    }
    for (int j = 1; j <= 17; j++)     //ʮ��������2�������η���2^16 ȡ��17
        for (int i = 1; i <= n; i++)  //ע��i j�ļ���˳�� �����
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &l, &r);
        len = ind(r - l + 1);
        ans = max(f[l][len], f[r - (1 << len) + 1][len]);  //��max�غ���Ҳû��ϵ
        printf("%d\n", ans);
    }
    return 0;
}
int ind(int x)  //��x����2����������η���ָ��
{
    int t = 0;
    while (x != 1)  //����==0
    {
        x = x >> 1;
        t++;
    }
    return t;
}
