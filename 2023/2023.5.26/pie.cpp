#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);
const int MAXN = 10005;

int n, f;
double A[MAXN];

bool ok(double area) {
	int sum = 0;
	for(int i = 0; i < n; i++) sum += floor(A[i] / area);
	return sum >= f + 1;
}

int main() {
//	freopen("pie.in", "r", stdin);
//	freopen("pie.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &f);
		double maxa = -1;
		
		for(int i = 0; i < n; i++) {
			int r;
			scanf("%d", &r);
			A[i] = PI*r*r; 
			maxa = max(maxa, A[i]);
		}
		double L = 0, R = maxa;
		while(R-L > 1E-5) {
			double M = (L + R) / 2;
			if(ok(M)) L = M; else R = M;
		}
		printf("%.4lf\n", L);
	}
	
	return 0;
}

/*
Sample Input
3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2

Sample Output
25.1327
3.1416
50.2655
*/
