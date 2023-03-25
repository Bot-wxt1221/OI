#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> G[MAXN];
list<int> out;
bool V[MAXN];
int N;

void dfs(int u) {
	V[u] = true;
	for( int i = 0; i < G[u].size(); i++ ) {
		int v = G[u][i];
		if( !V[v] ) dfs(v);
	}
	out.push_front(u);
}

int main() {
//	freopen("topological_sort.in", "r", stdin);
//	freopen("topological_sort.out", "w", stdout);
	
	int s, t, M;
	
	cin >> N >> M;
	
	for( int i = 0; i < N; i++) V[i] = false;
	
	for( int i = 0; i < M; i++) {
		cin >> s >> t;
		G[s].push_back(t);
	}
	
	for( int i = 0; i < N; i++ ) {
		if( !V[i] ) dfs(i);
	}	
	
	for( list<int>::iterator it = out.begin(); it != out.end(); it++ )
		cout << *it << endl;
	
	return 0;
}

/*
Sample Input
6 6
0 1
1 2
3 1
3 4
4 5
5 2

Sample Output
3
4
5
0
1
2
*/
