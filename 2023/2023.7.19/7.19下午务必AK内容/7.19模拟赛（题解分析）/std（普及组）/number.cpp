#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char c;
	int num = 0;
	for (int i = 1; i <= 8; ++i) {
		cin >> c;
		if (c == '1') ++num;
	}
	cout << num << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
