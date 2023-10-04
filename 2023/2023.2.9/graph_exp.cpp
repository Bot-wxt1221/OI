#include <bits/stdc++.h>
using namespace std;
const int N = 105;

int main() {
	freopen("graph_exp.in", "r", stdin);
	freopen("graph_exp.out", "w", stdout);
	int G[N][N];  //ÁÚ½Ó¾ØÕó 
	int n, u, k, v;
		
	memset(G, 0, sizeof(G)); 
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> u >> k;
		for(int j = 0; j < k; j++) {
			cin >> v;
			G[u][v] = 1;
		} 
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(j < n) cout << G[i][j] << " ";
			else cout << G[i][j];
		}
		cout << endl;	 
	}		
	
	return 0;
}

/*
Sample Input
4
1 2 2 4
2 1 4
3 0
4 1 3

Sample Output
0 1 0 1
0 0 0 1
0 0 0 0
0 0 1 0
*/
