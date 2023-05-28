#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;

int A[MAXN][MAXN];
int S[MAXN][MAXN];  //S[i][j] --- (0, 0,) ~ (i, j)�ľ����ܴݻٵ�Ŀ���ֵ֮�� 

int main() {
	freopen("laserbomb.in", "r", stdin);
	freopen("laserbomb.out", "w", stdout);
	
	int n, R; 
	cin >> n >> R;	
	
	int Row_Max, Col_Max;
	Row_Max = Col_Max = R;  //��¼������������߽� 	
		
	for(int i = 1; i <= n; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		x++, y++, A[x][y] = v;
		Row_Max = max(x, Row_Max);
		Col_Max = max(y, Col_Max);
	}
	
	//������ S
	memset(S, 0, sizeof(S));
	for(int x = 1; x <= Row_Max; x++) {
		for(int y = 1; y <= Col_Max; y++) {
			S[x][y] = S[x - 1][y] + S[x][y - 1] - S[x - 1][y - 1] + A[x][y];
		}
	} 
	
	//����߳�Ϊ R ���������дݻ�Ŀ�������ֵ��
	int ans = 0;
	for(int x = 1; x <= Row_Max; x++) {
		for(int y = 1; y <= Col_Max; y++) {
			ans = max(ans, S[x][y] - S[x][y - R] - S[x - R][y] + S[x - R][y - R]);
		}
	} 
	cout << ans;
	
	return 0;
}

/*
���������롿��laserbomb.in��
2 1
0 0 1
1 1 1

�������������laserbomb.out��
1

*/
