/*
思路1（贪心算法）
倒数第i个人，对总时间造成的贡献是：i*b; 因为他自己要等b[i]，其他n-i-1个人也要等b[i]

为使得总时间越小，应当把b大的放在后面；把b小的放在前面；

所以要对数组b进行排序；

*/

#include <iostream>
#include <cstdio> 
#include <algorithm>
using namespace std;
int a[1010];
int main() {
	freopen("t1.in", "r", stdin);
	freopen("t1.out", "w", stdout);
	int n;
	int sum = 0;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);  //从小到大排序
		for(int i = 0; i < n; i++){
			sum += (n - i) * a[i];   //倒数第n个人，对时间的贡献 
		}  //（自己要等 a[i]，其他 n-i-1个人也要等 a[i]
		cout << sum << endl;	
	} 
	return 0;
}
