#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105, MAXW = 10005;
int w[MAXN], v[MAXN];
int dp[MAXW]; //dp[i][j]---��ǰ i ����Ʒ��ѡȡ���ز����� j ʱ�� ��������Ʒ��ֵ�����ֵ
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
		for(int j = w[i]; j <= W; j++) {
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);	
			}			
		}	
	return dp[W];
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
