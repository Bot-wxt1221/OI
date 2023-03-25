#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int get(int x){
	int cnt = 0, ans = 0;//cnt存的是现在已经有几个数字出现了，ans存的是需要多少位有效数字 
	int t[10] = {0};//存的是当前已经有哪些数字出现了，没出现就是0，出现了就是1 
	long double y = sqrt((long double)x);//开根 
	while ((int)y / 10 != 0) y /= 10;//让这个数只有一位在小数点前面 
	while (y){ 
		if (cnt == 10) break;//如果已经把所有数找完了就结束 
		if (t[(int)y] == 0) cnt++, t[(int)y] = 1;//如果这个数还没有出现过 
		y = y - ((int)y % 10);
		y *= 10;//这两行，让这个数整体向前一位，并把之前那个数删掉 
		ans++; 
	}
	return ans;
}

int main(){
	int a;
	cin >> a;
	cout << get(a);
}
