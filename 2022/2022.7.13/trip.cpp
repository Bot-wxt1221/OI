#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define INF 2147483647
using namespace std;
long long dis[101][101], map[101][101], fs[101][101];
vector<int> vec;
long long n, m, a, b, c, ans = INF, mini, minj, mink;
void getf(int a, int b)  //加入转折点
{
    if (!fs[a][b])
        return;         //没有转折点
    getf(a, fs[a][b]);  //在a--fs[a][b]中找转折点
    vec.push_back(fs[a][b]);
    getf(fs[a][b], b);  //在fs[a][b]--b中找转折点
}
int main() {
//	freopen("trip.in","r",stdin);
//    freopen("trip.out","w",stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dis[i][j] = map[i][j] = INF;
        dis[i][i] = map[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a == b)
            continue;
        dis[a][b] = dis[b][a] = map[a][b] = map[b][a] = min(dis[a][b], c);  //去重
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i < k; i++)  //最小环
            for (int j = i + 1; j < k; j++)
                if ((long long)dis[i][j] + map[j][k] + map[k][i] < ans) {
                    ans = dis[i][j] + map[j][k] + map[k][i];
                    mini = i;
                    minj = j;
                    mink = k;  //记录三个环点
                }
        if (k < n)
            for (int i = 1; i <= n; i++)  // floyd
                for (int j = 1; j <= n; j++)
                    if (dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        fs[i][j] = k;  //记录环转折点，用于输出最小环
                    }
    }
    if (ans == INF)
        printf("No solution.");
    else {
        vec.push_back(mini);
        getf(mini, minj);  //查找i--j的转折点
        vec.push_back(minj);
        vec.push_back(mink);
        for (int i = 0; i < vec.size(); i++) printf("%d ", vec[i]);
    }
}
