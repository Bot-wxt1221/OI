#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int gx[5001];
int fact[100050],inv[100050];
vector<int> edge[100050];
int fa[100050];
int val[100050];
int n;

int qpow(int base,int tms) {
	int tmp = 1;
	while(tms)
	{
		if(tms & 1) tmp = tmp * 1ll * base % mod;
		base = base * 1ll * base % mod;
		tms >>= 1;
	}
	return tmp;
}

void dfs(int pos,int lst) {
	fa[pos] = lst;
	for(int i = 0; i < edge[pos].size(); i++) //for(auto v : edge[pos])
		if(edge[pos][i] != lst)
			dfs(edge[pos][i], pos);
}

int C(int n,int r) {
	return fact[n] * 1ll * inv[r] % mod * inv[n - r] % mod;
}

int main() {
//	freopen("spacetime.in", "r", stdin);
//	freopen("spacetime.out", "w", stdout);
	fact[0] = inv[0] = 1;
	for(int i = 1; i <= 100000; ++ i)
		fact[i] = fact[i - 1] * 1ll * i % mod,
		inv[i] = qpow(fact[i], mod - 2);
	scanf("%d",&n);
	for(int i = 1; i < n; ++ i) 	{
		int u,v;  scanf("%d%d", &u, &v);
		edge[u].push_back(v); edge[v].push_back(u);
	}
	for(int i = 1;i <= n; ++ i) scanf("%d",&val[i]);
	dfs(1,0);
	for(int i = 1;i <= min(5000,n); ++ i)	{
		long long base = fact[n - i] * 1ll * C(n,i) % mod;
		for(int j = 1;j <= i; ++ j)
			gx[i] = (gx[i] + 1ll * base * C(i,j) % mod * C(i - 1,j - 1) % mod * fact[i - j] % mod) % mod;
	}
	gx[1] = (gx[1] + fact[n]) % mod;
	long long ans = 0;
	for(int i = 1;i <= n; ++ i)	{
		for(int j = i,dep = 1;j;j = fa[j],dep ++)
			ans = (ans + gx[dep] * 1ll * val[j] % mod) % mod;
	}
	printf("%lld\n",ans);
	return 0;
}
