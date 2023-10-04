//递归实现 
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
int n, G[N][N];
int color[N], d[N], f[N], tt;

void dfs(int u) {	
	color[u] = GRAY;  //标记从 u 点开始访问 
	d[u] = ++tt; //最初的访问
	for(int v = 1; v <= n; v++) {
		if(G[u][v] == 0) continue;
		if(color[v] == WHITE) {
			dfs(v);
		}
	} 
	color[u] = BLACK;  // 标记 u 点已访问结束
	f[u] = ++tt; 
}


int main() {
	freopen("dfs.in", "r", stdin);
	freopen("dfs.out", "w", stdout);
	
	int u, v, k;
	cin >> n;
	memset(G, 0, sizeof(G));
	
	for(int i = 0; i < n; i++) {
		cin >> u >> k;
		for(int j = 0; j < k; j++) {
			cin >> v;
			G[u][v] = 1;
		}
	}
	
	for(int i = 1; i <= n; i++) color[i] = WHITE;
	tt = 0;
	
	for(int i = 1; i <= n; i++) {
		//以未访问的 i 为起点进行深搜
		if(color[i] == WHITE) dfs(i);		
	}
	
	for(int i = 1; i <= n; i++) {
		cout << i << " " << d[i] << " " << f[i] << endl;
	}	
	
	return 0;
}


/*
Sample Input 1
4
1 1 2
2 1 4
3 0
4 1 3
Sample Output 1
1 1 8
2 2 7
3 4 5
4 3 6

Sample Input 2
6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0
Sample Output 2
1 1 12
2 2 11
3 3 8
4 9 10
5 4 7
6 5 6

*/
