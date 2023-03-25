#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define INF 2147483647
using namespace std;
long long dis[101][101], map[101][101], fs[101][101];
vector<int> vec;
long long n, m, a, b, c, ans = INF, mini, minj, mink;
void getf(int a, int b)  //����ת�۵�
{
    if (!fs[a][b])
        return;         //û��ת�۵�
    getf(a, fs[a][b]);  //��a--fs[a][b]����ת�۵�
    vec.push_back(fs[a][b]);
    getf(fs[a][b], b);  //��fs[a][b]--b����ת�۵�
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
        dis[a][b] = dis[b][a] = map[a][b] = map[b][a] = min(dis[a][b], c);  //ȥ��
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i < k; i++)  //��С��
            for (int j = i + 1; j < k; j++)
                if ((long long)dis[i][j] + map[j][k] + map[k][i] < ans) {
                    ans = dis[i][j] + map[j][k] + map[k][i];
                    mini = i;
                    minj = j;
                    mink = k;  //��¼��������
                }
        if (k < n)
            for (int i = 1; i <= n; i++)  // floyd
                for (int j = 1; j <= n; j++)
                    if (dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        fs[i][j] = k;  //��¼��ת�۵㣬���������С��
                    }
    }
    if (ans == INF)
        printf("No solution.");
    else {
        vec.push_back(mini);
        getf(mini, minj);  //����i--j��ת�۵�
        vec.push_back(minj);
        vec.push_back(mink);
        for (int i = 0; i < vec.size(); i++) printf("%d ", vec[i]);
    }
}
