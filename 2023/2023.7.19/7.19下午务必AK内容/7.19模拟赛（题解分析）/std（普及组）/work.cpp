#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
int n, m, q, cnt, h[100010];
int dis1[100010], dis2[100010]; // dis1:偶数最短路，dis2:奇数最短路
struct node {
	int next, to;
} edg[200010];
queue<int> sq;

void sadd(int u, int v) {
	++cnt;
	edg[cnt].next = h[u];
	edg[cnt].to = v;
	h[u] = cnt;
}

void spfa() {
	dis1[1] = 0;
	sq.push(1);
	while (sq.size()) {
		int u = sq.front();
		sq.pop();
		for (int i = h[u]; i; i = edg[i].next) {
			int v = edg[i].to;
			if (dis1[u] != 0x3f3f3f3f) {
				if (dis2[v] > dis1[u] + 1) {
					dis2[v] = dis1[u] + 1;
					sq.push(v);
				}
			}
			if (dis2[u] != 0x3f3f3f3f) {
				if (dis1[v] > dis2[u] + 1) {
					dis1[v] = dis2[u] + 1;
					sq.push(v);
				}
			}
		}
	}
}

int main() {
	freopen("work.in", "r", stdin);
	freopen("work.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	int x, y;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		sadd(x, y);
		sadd(y, x);
	}
	memset(dis1, 0x3f, sizeof(dis1));
	memset(dis2, 0x3f, sizeof(dis2));
	spfa();
	while (q--) {
		int a, l;
		scanf("%d%d", &a, &l);
		if (a == 1 && h[a] == 0) printf("No\n"); // a是孤立点
		else if (dis1[a] == 0x3f3f3f3f && dis2[a] == 0x3f3f3f3f) printf("No\n"); // a
		else {
			if (l % 2) { // 奇数
				if (dis2[a] <= l) printf("Yes\n");
				else printf("No\n");
			} else {
				if (dis1[a] <= l) printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}
