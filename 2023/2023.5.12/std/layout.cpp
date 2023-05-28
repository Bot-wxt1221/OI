/*
如果A和B距离至多为 D则建边 A->B权值为 D，距离至少为 D则建边 B->A权值为 -D。
然后最短路。若有负权环则输出-1，若无法到达点 N则输出-2，否则直接输出1~N的距离即可。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf (1LL<<60)
#define ll long long
using namespace std;

int n, ml, md, cnt;
int t[1005], last[1005], fa[1005], q[1005];
ll dis[1005];
bool inq[1005];
struct data {
	int to, next, v;
} e[40005];

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

void insert(int u,int v,int w) {
	e[++cnt].to = v;
	e[cnt].next = last[u];
	last[u] = cnt;
	e[cnt].v = w;
}

int spfa() {
	for(int i = 1; i <= n; i++) dis[i] = inf;
	int head = 0, tail = 1;
	q[0] = 1;
	t[1]++;
	dis[1] = 0;
	while(head != tail) {
		int now = q[head];
		inq[now] = 0;
		head++;
		if(head == 1002) head = 0;
		for(int i = last[now]; i; i = e[i].next)
			if(dis[now] + e[i].v < dis[e[i].to]) {
				t[e[i].to]++;
				if(t[e[i].to] == n + 1) return 0;
				dis[e[i].to] = dis[now] + e[i].v;
				if(!inq[e[i].to]) {
					inq[e[i].to] = 1;
					q[tail++] = e[i].to;
					if(tail == 1002) tail = 0;
				}
			}
	}
	return 1;
}

int main() {
	freopen("layout.in", "r", stdin);
	freopen("layout.out", "w", stdout);
	n = read();
	ml = read();
	md = read();
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= ml; i++) {
		int a = read(), b = read(), d = read();
		d = abs(d);
		insert(a, b, d);
	}
	for(int i = 1; i <= md; i++) {
		int a = read(), b = read(), d = read();
		d = abs(d);
		insert(b, a, -d);
	}
	if(!spfa()) puts("-1");
	else if(dis[n] == inf) puts("-2");
	else printf("%lld\n",dis[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

