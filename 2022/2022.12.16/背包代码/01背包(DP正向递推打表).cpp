#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105, MAXW = 10005;
int w[MAXN], v[MAXN];
int dp[MAXN][MAXW]; //dp[k][c]---��ǰ k ����Ʒ��ѡȡ���ز����� c ʱ�� ��������Ʒ��ֵ�����ֵ
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
		for(int c = 0; c <= W; c++) {
			if(c < w[k]) dp[k][c] = dp[k - 1][c];
			else dp[k][c] = max(dp[k - 1][c], dp[k - 1][c - w[k]] + v[k]);
		}
	}
	return dp[n][W];
}

/*
���룺 
4 5
2 3
1 2
3 4
2 2
�����
7
*/ 
