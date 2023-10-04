#include <cstdio>
#include <stack>
using namespace std;
const int MAXN = 1000 + 10;

int n, target[MAXN];

int main() {
	freopen("rails.in", "r", stdin);
	freopen("rails.out", "w", stdout);
	while(scanf("%d", &n) == 1 && n) {
		int x;	
		while(n && scanf("%d", &x) == 1) {
			if(x == 0) { printf("\n"); break; }
			target[1] = x;
			stack<int> s;
			int A = 1, B = 1;
			for(int i = 2; i <= n; i++) scanf("%d", &target[i]);
			int ok = 1;
			while(B <= n) {
				if(A == target[B]) { A++; B++; }
				else if(!s.empty() && s.top() == target[B]) { s.pop(); B++; }
				else if(A <= n) s.push(A++);
				else { ok = 0; break; }
			}
			printf("%s\n", ok ? "Yes" : "No");
		} 			
	}
	return 0;
}

/*
Sample Input
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0

Sample Output
Yes
No

Yes
*/
