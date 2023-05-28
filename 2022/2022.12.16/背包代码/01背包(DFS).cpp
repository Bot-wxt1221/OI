
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, W;
int w[MAXN], v[MAXN];
int knapsack(int k, int c); //从第 k 个物品开始选择总重不超过 c 时， 背包里物品价值的最大值

int main() {
	cin >> n >> W;
	for(int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	cout << knapsack(1, W);
	
	return 0;
}

int knapsack(int k, int c) {
	int val;
	if(k == n + 1) val = 0; //已经没有剩余物品 
	else if(c < w[k]) val = knapsack(k+1, c); //背包装不下第 k 个物品 
	 //比较第 k个物品不放和放两种方案，取最大价值 
	else val = max(knapsack(k+1, c), knapsack(k+1, c-w[k]) + v[k]);	
	return val;
}

/*
输入： 
4 5
2 3
1 2
3 4
2 2
输出：
7
*/ 
