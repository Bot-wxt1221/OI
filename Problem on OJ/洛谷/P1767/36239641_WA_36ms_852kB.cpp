#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int pre[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string map[105];
char temp[205];
bool vised[105][105];
int _max = 0;
int n;
bool b[500];
void dfs(int x, int y);

signed main() {
//	freopen("family.in", "r", stdin);
//	freopen("family.out", "w", stdout);
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
		getline(cin, map[i]);
		_max = max(_max, int(map[i].size()));
		for (unsigned long j = 0; j < map[i].size(); j++) {
			b[map[i][j]] = 1;
		}

	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < _max; j++) {
			if (map[i][j] != ' ' && map[i][j] != '*' && map[i][j] != 0 && !vised[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

void dfs(int x, int y) {
	if (x <= 0 || y < 0 || y > _max || x > n)
		return ;
	if (map[x][y] == ' ' || map[x][y] == 0 || map[x][y] == '*')
		return ;
	for (int i = 0; i < 4; i++) {
		if (vised[x + pre[i][0]][y + pre[i][1]] == 1 || map[x][y] == ' ' || map[x][y] == '*' || map[x][y] == 0)
			continue;
		vised[x + pre[i][0]][y + pre[i][1]] = 1;
		dfs(x + pre[i][0], y + pre[i][1]);
	}
}
