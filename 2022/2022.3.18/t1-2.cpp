/*
思路2（贪心算法+考虑相邻两个人）

考虑相邻两个人，假设他们的时间是b[x]和b[y];

如果x在前面，代价是2*b[x]+b[y]

如果y在前面，代价是2*b[y]+b[x] 
 
两者比较，小的在前面

*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(const int &a,const int &b){//比较相邻两个人 
	return 2 * a + b < 2 * b + a;
} //a在前，两人需要总时间：a+(a+b)
  //b在前，两任需要总时间: b+(b+a) 

int main() {
	freopen("t1.in", "r", stdin);
	freopen("t1.out", "w", stdout);
	int a[1001];
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n, cmp);
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += (n - i) * a[i];
		}
		cout << sum << endl;
	}
	return 0;
}
