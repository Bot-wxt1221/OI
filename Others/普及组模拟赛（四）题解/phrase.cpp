#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

string a[1010], p, q;
int n, m, ans;

int main()
{
	freopen("phrase.in", "r", stdin);
	freopen("phrase.out", "w", stdout);
	scanf("%d%d\n", &n, &m);
	for(int i = 1; i <= n; i++) getline(cin, a[i]);
	for(int i = 1; i <= m; i++)
	{
		getline(cin, p);
		for(int j = 1; j <= n; j++) if (a[j].size() >= p.size())
			if (a[j].compare(0, p.size(), p) == 0) {ans++; break;}
	}
	printf("%d\n", ans);
	return 0;
} 
