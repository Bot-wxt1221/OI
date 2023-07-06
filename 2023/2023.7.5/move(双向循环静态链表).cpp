#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;

int Left[maxn], Right[maxn]; //˫��ѭ����̬������ͷ��㣩 

void link(int L, int R) { //����������໥���� 
	Right[L] = R; Left[R] = L;
}

int main() {
	int n, m, kase = 0;
	while(scanf("%d%d", &n, &m) == 2) {
		for(int i = 1; i <= n; i++) {
			Left[i] = i - 1;
			Right[i] = (i + 1) % (n + 1);  //β������ͷ����� 
		}
		Right[0] = 1; Left[0] = n; 
		int op, X, Y;
		int inv = 0; //��ת��ǣ�����һ���޸�����Ԫ��ָ�룬���ʱ���� invֵ��ͬ����		            
		
		while(m--) {
			scanf("%d", &op);
			if(op == 4) inv = !inv;
			else {
				scanf("%d%d", &X, &Y);
				if(op == 1 && X == Left[Y])  continue;
				if(op == 2 && Y == Right[X]) continue;
				if(op == 3 && Right[Y] == X) swap(X, Y);  //X �� Y ���, ���Ƚ������������ں�� link ͳһ����link�ǰ������������� 
				if(op != 3 && inv) op = 3 - op; //�� op Ϊ 1�� 2�� inv = 1ʱ����ʱop �ȼ��� 3-op, op = 3���� inv Ӱ�� 			
						
				int LX = Left[X], RX = Right[X], LY = Left[Y], RY = Right[Y];
				if(op == 1)  { link(LX, RX); link(LY, X); link(X, Y); }
				else if(op == 2) { link(LX, RX); link(Y, X); link(X, RY);}
				else if(op == 3) {
					if(Right[X] == Y) { link(LX, Y); link(Y, X); link(X, RY); }
					else { link(LX, Y); link(Y, RX); link(LY, X); link(X, RY); }
				}
			}
		}
		
		//���
		int b = 0;
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			b = Right[b];
			if(i % 2 == 1) ans += b;
		} 
		
		if(inv && n % 2 == 0) ans = (long long)n * (n + 1) / 2 - ans;
		printf("Case %d: %lld\n", ++kase, ans);
	}
	
	return 0;
}

/*
Sample Input
6 4
1 1 4
2 3 5
3 1 6
4
6 3
1 1 4
2 3 5
3 1 6
100000 1
4

Sample Output
Case 1: 12
Case 2: 9
Case 3: 2500050000
*/
