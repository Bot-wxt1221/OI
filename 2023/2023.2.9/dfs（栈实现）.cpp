//栈实现 
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
int n, G[N][N];
int color[N], d[N], f[N], tt;
int nt[N];  

//按编号顺序获取与 u 相邻的 v
int nxt(int u) {
	for(int v = nt[u]; v <= n; v++) {
		nt[u] = v + 1;
		if(G[u][v]) return v;
	}
	return -1;
} 

//用栈实现dfs
void dfs(int u) {
	memset(nt, 0, sizeof(nt));
	stack<int> S;
	S.push(u);
	color[u] = GRAY;
	d[u] = ++tt;
	
	while(!S.empty()) {
		int i = S.top();
		int j = nxt(i);
		if(j != -1) {
			if(color[j] == WHITE) {
				color[j] = GRAY;
				d[j] = ++tt;
				S.push(j);
			}
		} else {
			S.pop();
			color[i] = BLACK;
			f[i] = ++tt;
		}
	}
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
