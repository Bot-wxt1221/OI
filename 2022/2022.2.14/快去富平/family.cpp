#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int pre[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string map[105];
bool vised[105][205];
int n;
void dfs(int x, int y);

signed main() {
	freopen("family.in", "r", stdin);
	freopen("family.out", "w", stdout);
	scanf("%d", &n);
	getline(cin, map[1]);
	for (int i = 1; i <= n; i++) {
		getline(cin, map[i]);
//		cout << map[i] << endl;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] >= 'a' && map[i][j] <= 'z' && !vised[i][j]) {
				vised[i][j] = 1;
//				cout << i << ' ' << j << " " << map[i][j] << endl;
				dfs(i, j);
				ans++;
//				cout << "#" << endl;
			}
		}
	}
	cout << ans;
	return 0;
}

void dfs(int x, int y) {
	if (x <= 0 || y < 0 || y >= map[x].size() || x > n)
		return ;
	if (map[x][y] < 'a' || map[x][y] > 'z')
		return;
	vised[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		if (vised[x + pre[i][0]][y + pre[i][1]] == 1)
			continue;
		dfs(x + pre[i][0], y + pre[i][1]);
	}
	return ;
}
