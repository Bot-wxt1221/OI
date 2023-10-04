#include <bits/stdc++.h>
using namespace std;

const long long p = 1000000007LL;
long long f[100005];
struct smt {
	long long ls, rs;
	smt *l, *r;
	long long kt, bt, s;
	smt() {}
	smt(long long, long long);
	void put_tag(long long k, long long b) {
		kt += k;
		bt += b;
		kt %= p;
		bt %= p;
		s = (s + b * (rs - ls + 1) + k * f[rs - ls + 1]) % p;
	}
	void push_down() {
		if(kt || bt) {
			l->put_tag(kt, bt);
			r->put_tag(kt, (bt + (l->rs-l->ls+1) * kt) % p);
			kt = bt = 0;
		}
	}
	void add(long long la, long long ra, long long k, long long &b) {
		if(la <= ls && rs <= ra) {
			put_tag(k, b);
			b = (b + (rs - ls + 1) * k) % p;
			return;
		}
		push_down();
		if(la <= l->rs) l->add(la, ra, k, b);
		if(r->ls <= ra) r->add(la, ra, k, b);
		s = (l->s+r->s) % p;
	}
	long long sum(long long la, long long ra) {
		if(la <= ls && rs <= ra) return s;
		push_down();
		long long s = 0;
		if(la <= l->rs) s += l->sum(la, ra);
		if(r->ls <= ra) s += r->sum(la, ra);
		s %= p;
		return s;
	}
};

smt *rt;
smt::smt(long long la, long long ra) {
	ls = la;
	rs = ra;
	kt = bt = s = 0;
	if(ls == rs) {
		l = r = 0;
		return;
	} else {
		long long mid = (ls + rs) >> 1;
		l = new smt(ls, mid);
		r = new smt(mid + 1, rs);
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	long long n,q;
	cin >> n >> q;
	
	for(long long i = 1; i <= n; ++i) f[i] = f[i-1] + (i-1);
	rt = new smt(1, n);
	for(; q; --q) {
		long long tp, l, r;
		cin >> tp >> l >> r;
		if(tp == 1) {
			long long k, b;
			cin >> k >> b;
			rt->add(l, r, k, b);
		} else {
			cout << rt->sum(l,r) << '\n';
		}
	}
	
	return 0;
}

/*
ÊäÈë£º
5 5
1 2 4 1 0
2 1 3
1 3 5 0 1
2 2 5
2 1 5

Êä³ö£º 
1
6
6
*/

