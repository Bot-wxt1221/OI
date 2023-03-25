#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105, MAXW = 10005;
int w[MAXN], v[MAXN];
int dp[MAXN][MAXW]; //dp[i][j]---��ǰ i ����Ʒ��ѡȡ���ز����� j ʱ�� ��������Ʒ��ֵ�����ֵ
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
���룺 
3 7
3 4
4 5
2 3

�����
10 (1��ѡ1����3��ѡ2��)
*/ 
