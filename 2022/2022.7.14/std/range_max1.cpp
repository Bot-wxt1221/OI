#include <iostream>
#include <cstdio>
using namespace std;
int a[1000007], f[1000007][18], ans;  //数组要开大一点 注意是十万不是一万
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
    for (int j = 1; j <= 17; j++)     //十万内最大的2的整数次方是2^16 取到17
        for (int i = 1; i <= n; i++)  //注意i j的计算顺序 先完成
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &l, &r);
        len = ind(r - l + 1);
        ans = max(f[l][len], f[r - (1 << len) + 1][len]);  //求max重合了也没关系
        printf("%d\n", ans);
    }
    return 0;
}
int ind(int x)  //求x以内2的最大整数次方的指数
{
    int t = 0;
    while (x != 1)  //不是==0
    {
        x = x >> 1;
        t++;
    }
    return t;
}
