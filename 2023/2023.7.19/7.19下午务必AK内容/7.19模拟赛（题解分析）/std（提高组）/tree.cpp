//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;

int fa[1000050];

int find_fa(int po) {
	return fa[po] == po ? po : fa[po] = find_fa(fa[po]);
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++ i)	fa[i] = i;
	long long w = 0;
	//int cnt = 0;
	for(int i = n / 2; i >= 1; -- i) {
		for(int j = 1; (j + 1) * i <= n; ++ j) {
			if(find_fa(j * i) != find_fa((j + 1) * i)) {
				int f1 = find_fa(j * i), f2 = find_fa(j * i + i);
				fa[f1] = f2;
				w += i;
				//cnt ++;
			}
		}
	}
//	cerr << cn << endl;
	int u = find_fa(1);
//	for(int i = 1;i <= n; ++ i)
//		assert(find_fa(i) == u);
	printf("%lld %d\n", w, n - 1);
}
