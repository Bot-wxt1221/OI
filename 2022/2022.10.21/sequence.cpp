#include <cstdio>
#include <cstring>
#include <iostream>
#define cs const
#define pb push_back
using namespace std;
cs int mod = 1e9 + 7, iv6 = (mod + 1) / 6; 
int add(int a, int b){
	return (a + b) % mod;
} 
int dec(int a, int b) {
	return (a - b + mod) % mod;
}
int mul(int a, int b) {
	return 1ll * a * b % mod;
}
void Add(int &a, int b) {
	a = add(a, b);
}
void Dec(int &a, int b) {
	a = dec(a, b);
}
void Mul(int &a, int b) {
	a = mul(a, b);
}
int ksm(int a, int b) {
	int c = 1; for(; b; b >>= 1, Mul(a, a))
	if(b & 1) Mul(c, a); return c;
}
cs int N = 1e6 + 5; 
int n, a[N];

int c2(int x) {
	return (1ll * x * (x - 1) / 2) % mod;
}
int c3(int x) {
	int a = mul(x, x + 1);
	Mul(a, x * 2 + 1);
	Mul(a, iv6);
	return a; 
}

struct mat {
	int a[2][2];
	mat() {
		memset(a, 0, sizeof a);
	}
	mat operator * (cs mat &x) {
		mat y; 
		for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
		for(int k = 0; k < 2; k++)
		Add(y.a[i][j], mul(a[i][k], x.a[k][j]));
		return y; 
	}
} p[N], q[N], I; 

int main() {
	
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	cin >> n; 
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		p[i].a[0][0] = mul(a[i], a[i] + 1);
		Dec(p[i].a[0][0], c2(a[i] + 1));
		Add(p[i].a[1][0], mul(a[i], c2(a[i] + 1)));
		Dec(p[i].a[1][0], c3(a[i]));
		p[i].a[0][1] = (a[i] + 1) % mod;
		p[i].a[1][1] = c2(a[i] + 1);
		q[i] = p[i];
		Dec(q[i].a[0][1], 1);
		Dec(q[i].a[1][1], a[i]);
	}
	I.a[0][0] = I.a[1][1] = 1;
	p[n + 1] = q[0] = I;  
	for(int i = n; i; i--) p[i] = p[i] * p[i + 1];
	for(int i = 1; i <= n; i++) q[i] = q[i - 1] * q[i];
	int ans = 0; 
	for(int i = 1; i <= n; i++) {
		mat z = p[i + 1];
		z = z * q[i - 1];
		int P = z.a[1][0], Q = z.a[1][1];
		int c = mul(Q, a[i]); 
		Add(c, P);
		Add(ans, c);
	}
	cout << ans; 
	return 0; 
}
