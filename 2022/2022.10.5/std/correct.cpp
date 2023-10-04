#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//Global Variables & Definitions
#define MAXN 1010
#define MAXM 1010

#define MS(arr, x) memset(arr, x, sizeof(arr))

int N, M;
//End Global Variables & Definitions

//Map
struct edge {
	int v, next;
} e[MAXM];

int h[MAXN];
int ecnt;

int in[MAXN];

inline void init_edge() {
	MS(h, ecnt = -1);
	//MS(in, 0);
}

inline void adde(int u, int v) {
	++in[v];
	
	++ecnt;
	e[ecnt].v = v;
	e[ecnt].next = h[u];
	h[u] = ecnt;
}

priority_queue<int, vector<int>, greater<int> > q;
//End Map

//Main Structure
int ans[MAXN];

inline void ir() {
	freopen("correct.in", "r", stdin);
	freopen("correct.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	
	int u, v;
	init_edge();
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &u, &v);
		adde(u, v);
	}
	
	for (int i = 1; i <= N; ++i) if (!in[i]) q.push(i);
}

int main() {
	ir();
	
	int cnt = 0;
	while (!q.empty()) {
		int u = q.top(); q.pop();
		ans[cnt++] = u;
		
		for (int i = h[u]; ~i; i = e[i].next) {
			int v = e[i].v;
			if (!(--in[v])) q.push(v);
		}
	}
	
	if (cnt != N) return 2;
	for (int i = 0; i < N; ++i) printf(i ? " %d" : "%d", ans[i]);
	putchar('\n');
	
	return 0;
}

