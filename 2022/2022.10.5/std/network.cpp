#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

//Global Variables & Definitions
#define MAXN 100100
#define MAXT 100100
#define MAXM 200200

#define MS(arr, x) memset(arr, x, sizeof(arr))

#define MOD 998244353

int N, T;
//End Global Variables & Definitions

//Map
struct edge {
	int v, next;
} e[MAXM];

int h[MAXN];
int ecnt;

inline void init_edge() {
	MS(h, ecnt = -1);
}

inline void adde(int u, int v) {
	++ecnt;
	e[ecnt].v = v;
	e[ecnt].next = h[u];
	h[u] = ecnt;
}

inline void adde_d(int a, int b) {
	adde(a, b);
	adde(b, a);
}
//End Map

//Tree
namespace Tree {
	int f[MAXN];
	int l[MAXN], r[MAXN];
	int size[MAXN], hs[MAXN], hss[MAXN];
	int hf[MAXN];
	int dep[MAXN];
	
	int LCA(int a, int b) {
		while (hf[a] != hf[b]) {
			int aa = hf[a], bb = hf[b];
			if (dep[aa] >= dep[bb])
				a = f[aa];
			else
				b = f[bb];
		}
		
		if (dep[a] >= dep[b]) swap(a, b);
		return a;
	}
	
	int Q_dis(int a, int b) {
		int l = LCA(a, b);
		return dep[a] + dep[b] - dep[l] * 2;
	}
	
	void DFS1(int u, int d) {
		int rm = l[u] = -1, v;
		size[u] = 1; dep[u] = d;
		hs[u] = hss[u] = -1;
		
		for (int i = h[u]; ~i; i = e[i].next) if((v = e[i].v) != f[u]) {
			f[v] = u;
			if (~rm) rm = r[rm] = v;
			else rm = l[u] = v;
			
			DFS1(v, d + 1);
			
			size[u] += size[v];
			if (size[v] > hss[u]) {
				hs[u] = v;
				hss[u] = size[v];
			}
		}
	}
	
	void DFS2(int u) {
		if (f[u] == -1 || hs[f[u]] != u) hf[u] = u;
		else hf[u] = hf[f[u]];
		
		for (int i = l[u]; ~i; i = r[i]) DFS2(i);
	}
	
	void init() {
		MS(r, -1);
	}
}
//End Tree

//Union-Find Set
namespace UF {
	int f[MAXN];
	
	void init() {
		for (int i = 0; i < MAXN; ++i) f[i] = i;
	}
	
	int find(int x) {
		return f[x] == x ? x : (f[x] = find(f[x]));
	}
	
	void link(int u, int v) {
		f[find(u)] = find(v);
	}
}
//End Union-Find Set

//Main Structure
inline void ir() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	
	scanf("%d%d", &N, &T);
	
	init_edge();
	int a, b;
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &a, &b);
		adde_d(a, b);
	}
	
	Tree::init();
	Tree::DFS1(1, 0);
	Tree::DFS2(1);
	
	UF::init();
}

int main() {
	ir();
	
	int R = 0;
	
	char o[2]; int a, b;
	for (int i = 1; i <= T; ++i) {
		scanf("%s", o);
		
		if (o[0] == 'C') { //Connect
			scanf("%d", &a); --a;
			UF::link(e[a << 1].v, e[(a << 1) | 1].v);
		} else { //Query
			scanf("%d%d", &a, &b);
			if (UF::find(a) == UF::find(b)) {
				int K = Tree::Q_dis(a, b);
				
				R = (R + (i ^ K)) % MOD;
			} else {
				R ^= (i + a + b);
			}
		}
	}
	
	printf("%d\n", R);
	
	return 0;
}

