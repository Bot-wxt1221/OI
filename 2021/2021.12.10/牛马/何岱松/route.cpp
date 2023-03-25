#include <cstdio>
#include <iostream>
using namespace std;

int vis[20][20][20][20];
int t[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int ans = 0;
int n, m;
//0ио 1вС 2об 3ср 

inline void dfs(int x, int y, int p, int q){
	//cout << x << y << p << q << endl;
	if(x == n && y == m && p == 1 && q == 1){
	//	cout <<endl;
		ans++;
		return;
	}
	for(int i = 2; i <= 3; i++){
		for(int j = 0; j <= 1; j++){
			int tx = x + t[i][0];
			int ty = y + t[i][1];
			int tp = p + t[j][0];
			int tq = q + t[j][1];
			if(1 <= tx && tx <= n && 1 <= ty && ty <= m &&
			   1 <= tp && tp <= n && 1 <= tq && tq <= m &&
			   !vis[x][y][tx][ty] && !vis[p][q][tp][tq]){
				vis[x][y][tx][ty] = vis[tx][ty][x][y] = vis[p][q][tp][tq] = vis[tp][tq][p][q] = 1;
				dfs(tx, ty, tp, tq);
				vis[x][y][tx][ty] = vis[tx][ty][x][y] = vis[p][q][tp][tq] = vis[tp][tq][p][q] = 0;
			}
		}
	}
}
int main(){
	freopen("route.in", "r", stdin);
	freopen("route.out", "w", stdout);
	cin >> n;
	n = m = n + 1;
	dfs(1, 1, n, m);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
