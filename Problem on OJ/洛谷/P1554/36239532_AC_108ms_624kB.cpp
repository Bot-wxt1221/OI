#include <iostream>
#include <sstream>
using namespace std;
int ans[10];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		int temp=i;
		while (temp) {
			ans[temp % 10]++;
			temp = temp / 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}