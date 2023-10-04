#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 500500;
typedef long long ll;

int n, m = 5e5, a, b, v[N], head[N], cnt, as[N], dep[N];
ll tp;

struct edge{int t, next;} ed[N*2];
void adde(int f, int t) { ed[++cnt] = (edge) {t, head[f]}; head[f] = cnt; ed[++cnt] = (edge){f,head[t]}; head[t] = cnt; }

struct BIT {
	int tr[N];
	void add(int x, int v) {for(int i = x; i <= m; i += i&-i) tr[i] += v;}
	int que(int x) {int as = 0; for(int i = x; i; i -= i&-i) as += tr[i]; return as;}
} tr1, tr2;

void dfs(int u, int fa) {
	tp -= tr1.que(v[u]); tp += dep[u];
	as[u] += tr1.que(v[u]) - (tr2.que(m) - tr2.que(v[u]));
	tr1.add(v[u], 1); tr2.add(v[u], 1);
	for(int i = head[u]; i; i = ed[i].next) if(ed[i].t != fa) dep[ed[i].t] = dep[u] + 1, dfs(ed[i].t, u);
	tr1.add(v[u], -1);
	as[u] += tr2.que(m) - tr2.que(v[u]);
	as[u] -= dep[u];
}

int rd() {
	int as = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') as = as * 10 + c - '0', c = getchar();
	return as;
}

void wt1(ll x) {
	if(!x) return;
	ll tp = x / 10;
	wt1(tp); putchar('0' + x - tp * 10);
}

void wt(ll x) {
	if(!x) putchar('0');
	else wt1(x);
	putchar(' ');
}

int main() {
	freopen("stardust.in", "r", stdin);
	freopen("stardust.out", "w", stdout);
	n = rd();
	for(int i = 1; i <= n; i++) v[i] = rd(), v[i]++;
	for(int i = 1; i < n; i++) a = rd(), b = rd(), adde(a,b);
	tp = 1ll * n * (n - 1) / 2; dfs(1, 0);
	sort(as + 1, as + n + 1);
	wt(tp);
	for(int i = 1; i <= n; i++) tp = tp - (n - i) + as[i], wt(tp);
	return 0;
}

