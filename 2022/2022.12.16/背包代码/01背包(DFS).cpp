
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, W;
int w[MAXN], v[MAXN];
int knapsack(int k, int c); //�ӵ� k ����Ʒ��ʼѡ�����ز����� c ʱ�� ��������Ʒ��ֵ�����ֵ

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
	if(k == n + 1) val = 0; //�Ѿ�û��ʣ����Ʒ 
	else if(c < w[k]) val = knapsack(k+1, c); //����װ���µ� k ����Ʒ 
	 //�Ƚϵ� k����Ʒ���źͷ����ַ�����ȡ����ֵ 
	else val = max(knapsack(k+1, c), knapsack(k+1, c-w[k]) + v[k]);	
	return val;
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
