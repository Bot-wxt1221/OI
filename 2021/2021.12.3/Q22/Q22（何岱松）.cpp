#include <cstdio>
#include <iostream>
using namespace std;

int a[105] = {1, 0, 1, 0, 2, 0, 5};
//一开始的0个点也是1种方案是为了之后相乘 
int f(int x){
	if(a[x] != 0) return a[x];//如果已经算过这个 
	int ans = 0;//有多少种方案 
	for(int i = 0; i <= x - 2; i += 2){
	//假设已经有一对连线已经固定，那么整个点阵就被这条线分为了两部分，每个部分分开算，再乘起来 
		ans += f(i) * f(x - 2 - i);
	}
	a[x] = ans; //记录当前的结果 
	return ans;
}

int main(){
	int n;cin >> n;
	cout << f(n);
}
