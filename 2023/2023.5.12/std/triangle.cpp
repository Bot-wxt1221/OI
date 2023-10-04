#include <bits/stdc++.h>
using namespace std;

const long long inf = (long long)1E18 + 1;
const int m = 100;
long long c[205][205];

long long C(long long n, long long m) {
	long long s = 1;
	for(long long i = 0; i < m; ++i) {
		s = s * (n - i) / (i + 1);
		if(s >= inf) return inf;
	}
	return s;
}

long long chk(long long n, long long k) {
	long long L = m + 1, R = 2000000000LL;
	while(L <= R) {
		int mid = (L + R) >> 1;
		if(C(mid, k) <= n) L = mid + 1;
		else R = mid - 1;
	}
	if(C(L - 1, k) == n) return L - 1;
	else return inf;
}

long long calc(long long n) {
	for(int i = 0; i <= m; ++i) for(int j = 0; j <= i; ++j) if(c[i][j] == n) return i;
	long long ans = n;
	for(int i = 2; i <= m && c[m][i] < inf; ++i) {
		ans = min(ans, chk(n, i));
	}
	return ans;
}

int main() {
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);

	//预处理 
	for(int i = 0; i <= m; ++i) {
		for(int j = 1; j < i; ++j) c[i][j] = min(c[i-1][j-1]+c[i-1][j], inf);
		c[i][0] = c[i][i] = 1;
	}
	
	int t; cin >> t; 
	
	for(; t; --t) {
		int n; cin >> n;
		cout << calc(n) + 1 << "\n";
	}
	
	return 0;
}


/*
输入：
6
1
2
3
4
5
6

输出：
1
3
4
5
6
5
*/
