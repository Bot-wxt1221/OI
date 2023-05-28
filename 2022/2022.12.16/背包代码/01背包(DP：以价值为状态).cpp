#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105, MAXV = 105;
const int INF = 0X3f3f3f3f;
int w[MAXN], v[MAXN];
int dp[MAXN][MAXN * MAXV + 1]; //dp[i][j]---从前 i 个 物品中选取价值总和为 j 时总重量的最小值。 
int knapsack(int n, int W); 

int main() {
	int n, W;
	cin >> n >> W;
	for(int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}	
	cout << knapsack(n, W);
	
	return 0;
}

int knapsack(int n, int W) {
	fill(dp[0], dp[0] + MAXN * MAXV + 1, INF); 
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= MAXN * MAXV; j++) {
			if(j < v[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
		}
	}
	int ans = 0;
	for(int i = 0; i <= MAXN * MAXV; i++) 
		if(dp[n][i] <= W) ans = i;
	return ans;
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
