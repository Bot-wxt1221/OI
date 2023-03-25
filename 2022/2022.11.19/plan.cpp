#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef const int& int_;
const int N = 1007;
struct Node
{
	int Data, Left, Right;
	
	Node() {Data = 0; Left = Right = -1;}
} a[N];
int f[N][N];

int Solve(int_ Root, int_ k)
{
	if (Root < 0 || !k) return 0;
	if (f[Root][k]) return f[Root][k];
	
	int i;
	f[Root][k] = Solve(a[Root].Right, k);
	for (i = 0; i < k; ++i)
		f[Root][k] = max(f[Root][k],
		Solve(a[Root].Left, i) + Solve(a[Root].Right, k - i - 1) + a[Root].Data);
	
	return f[Root][k];
}

int main()
{
	int i, m, n, b;
	freopen("plan.in", "r", stdin);
	freopen("plan.out","w", stdout);
	cin >> m >> n;
	for (i = 1; i <= m; ++i)
	{
		cin >> b >> a[i].Data;
		a[i].Right = a[b].Left; a[b].Left = i;
	}
	
	cout << Solve(0, n + 1) << endl;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

