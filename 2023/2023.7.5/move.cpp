#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int r[100000+5], l[100000+5];

void init(int n) {
	for(int i = 1; i <= n; i++) {
		l[i] = i - 1;
		r[i] = (i + 1) % (n + 1);
	}
	r[0] = 1;
	l[0] = n;
}

void link(int L, int R) {
	r[L] = R;
	l[R] = L;
}

int main() {
	freopen("move.in", "r", stdin);
	freopen("move.out", "w", stdout);
	int n, m, a, x, y, k = 0;
	bool flag; 		
	while(cin >> n >> m) {
		flag = false;
		init(n);
		for(int i = 0; i < m; i++) {
			cin >> a;
			if(a == 4){
				flag = !flag;//∑≠◊™ 
			}				
			else {
				cin >> x >> y;
				if(a == 3 && r[y] == x) swap(x, y);
				if(a != 3 && flag)	a = 3 - a;
				if(a == 1 && x == l[y]) continue;
				if(a == 2 && x == r[y])	continue;
				int Lx = l[x], Rx = r[x], Ly = l[y], Ry = r[y];
				if(a == 1) {
					link(Lx, Rx);//…æ≥˝x 
					link(Ly, x);
					link(x, y);//x≤Â»Îy◊Û 
				}
				else if(a == 2)	{
					link(Lx, Rx);//…æ≥˝x 
					link(y, x);
					link(x, Ry);//x≤Â»Îy”“
				}
				else if(a == 3)	{
					if(r[x]==y)	{
						link(Lx, y);
						link(y, x);
						link(x, Ry);
					}
					else {
						link(Lx, y);//ΩªªªŒª÷√ 
						link(y, Rx);
						link(Ly, x);
						link(x, Ry);
					}
				}
			}	
		}
		int t = 0;
		long long sum = 0;
		for(int i = 1; i <= n; i++) {
			t = r[t];
			if(i % 2 == 1)	sum += t;
		}
		if(flag && n % 2 == 0)
			sum = (long long) n * (n + 1) / 2 - sum;
		cout << "Case " << ++k << ": " << sum << endl;
	}
	return 0;
 } 
