#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105, MAXW = 10005;
int w[MAXN], v[MAXN];
int dp[MAXN][MAXW]; //dp[i][j]---从前 i 种物品中选取总重不超过 j 时， 背包里物品价值的最大值
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
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= W; j++) {
			for(int k = 0; k * w[i] <= j; k++) {				
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);	
			}			
		}
	}
	return dp[n][W];
}

/*
输入： 
3 7
3 4
4 5
2 3

输出：
10 (1号选1个，3号选2个)
*/ 
