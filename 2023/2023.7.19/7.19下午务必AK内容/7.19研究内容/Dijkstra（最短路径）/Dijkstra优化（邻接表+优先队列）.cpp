#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int INF = (1 << 20);
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n;
vector < pair<int, int> > adj[MAXN]; //加权有向图的邻接表

void dijkstra() {
	priority_queue < pair<int, int> > PQ;
	int color[MAXN];
	int d[MAXN];
	for(int i = 0; i < n; i++) {
		d[i] = INF;
		color[i] = WHITE;
	}
	
	d[0] = 0;
	PQ.push(make_pair(0, 0));
	color[0] = GRAY;
	while(!PQ.empty()) {
		pair<int, int> f = PQ.top(); PQ.pop();
		int u = f.second;
		
		color[u] = BLACK;
		
		//取出最小值， 如果不是最短路径则忽略
		if(d[u] < f.first * (-1)) continue;
		
		for(int j = 0; j < adj[u].size(); j++) {
			int v = adj[u][j].first;
			if(color[v] == BLACK) continue;
			if(d[v] > d[u] + adj[u][j].second) {
				d[v] = d[u] + adj[u][j].second;
				//priority_queue是最大堆，因此要乘以 -1.
				PQ.push(make_pair(d[v] * (-1), v));
				color[v] = GRAY;
			}
		} 		 
	}
	
	for(int i = 0; i < n; i++) {
		cout << i << " " << ( d[i] == INF ? -1 : d[i] ) << endl;
	}
} 


int main() {
	int k, u, v, c;
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> u >> k;
		for(int j = 0; j < k; j++) {
			cin >> v >> c;
			adj[u].push_back(make_pair(v, c));
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
