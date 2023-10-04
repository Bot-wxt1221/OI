#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int INF = (1 << 21);
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n, G[MAXN][MAXN];

void dijkstra() {
	int minv;
	int d[MAXN], color[MAXN];
	
	for(int i = 0; i < n; i++) {
		d[i] = INF;
		color[i] = WHITE;
	}
	
	d[0] = 0;
	color[0] = GRAY;
	while(1) {
		minv = INF;
		int u = -1;
		for(int i = 0; i < n; i++) {
			if(minv > d[i] && color[i] != BLACK) {
				u = i;
				minv = d[i];
			}
		}
		if( u == -1) break;
		color[u] = BLACK;
		for(int v = 0; v < n; v++) {
			if(color[v] != BLACK && G[u][v] != INF) {
				if(d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					color[v] = GRAY;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		cout << i << " " << ( d[i] == INF ? -1 : d[i] ) << endl;
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			G[i][j] = INF;
		}
	}
	
	int k, c, u, v;
	for(int i = 0; i < n; i++) {
		cin >> u >> k;
		for(int j = 0; j < k; j++) {
			cin >> v >> c;
			G[u][v] = c;
		} 
	}
	
	dijkstra();
		
	return 0;
}

/*
Sample Input 1
5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3

Sample Output 1
0 0
1 2
2 2
3 1
4 3
*/
