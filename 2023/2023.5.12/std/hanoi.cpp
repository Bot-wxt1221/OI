#include <bits/stdc++.h>
using namespace std;

void hanoi(unsigned long long n, unsigned long long int x, char a, char b, char c) {
	if(x == (1ULL << (n - 1))) {
		cout << n << " " << a << "->" << b << "\n";
		return;
	}
	if(x < (1ULL << (n - 1))) hanoi(n - 1, x, a, c, b);
	else hanoi(n - 1, x - (1ULL << (n - 1)), c, b, a);	
}

int main() {
	freopen("hanoi.in", "r", stdin);
	freopen("hanoi.out", "w", stdout);
	unsigned long long n, x;
	cin >> n >> x;	
	hanoi(n, x, 'a', 'b', 'c');
	
	return 0;
}

/*
ÊäÈë£º 
2 1

Êä³ö£º 
1 a->c
*/
