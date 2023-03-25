#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105, MAXW = 10005;
int w[MAXN], v[MAXN];
int dp[MAXW]; //dp[c]---从前 k 个物品中选取总重不超过 c 时， 背包里物品价值的最大值
int knapsack(int n, int W); 

int main() {
	int n, W;
	cin >> n >> W;
	for(int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	memset(dp, 0, sizeof(dp));	
	cout << knapsack(n, W);
	
	return 0;
}

int knapsack(int n, int W) {
	for(int k = 1; k <= n; k++) {
		for(int c = W; c >= w[k]; c--) { //注意要反过来循环 
			dp[c] = max(dp[c], dp[c - w[k]] + v[k]);
		}
	}
	return dp[W];
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
