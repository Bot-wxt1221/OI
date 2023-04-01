#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;
//�ȼ����⣺ѡ�����������ʹ�����ǵ� xor�����ֵΪ0��

int bitcount(int x) {
	return x == 0 ? 0 : bitcount(x/2) + (x&1);
}
 
int A[MAXN];  //��ͷ�ַ���������ÿ����ĸ���ִ�������ż�ԣ�1---��Σ� 0---ż��
map<int, int> T;  // T[x] = i����ʾ xorֵΪ x ��Ӧ�Ĺ�ͷ�ַ������Ӽ���ţ���ѡ���˶��ٸ���ͷ�ַ����� 
string bone; 


int main() {
	freopen("jurassicremains.in", "r", stdin);
	freopen("jurassicremains.out", "w", stdout);
	int N; 
	while(cin >> N) {
		for(int i = 0; i < N; i++) {
			cin >> bone;
			A[i] = 0;
			for(int j = 0; j < bone.length(); j++) {
				A[i] ^= (1 << (bone[j] - 'A'));				
			}
		}
		
		// ����ǰ N/2 ��Ԫ�ص������Ӽ��� xorֵ, ��¼�� T �� 
		T.clear();
		int n1 = N / 2;
		for(int i = 0; i < (1 << n1); i++) {
			int x = 0;
			for(int j = 0; j < n1; j++)  if(i & (1 << j)) x ^= A[j];
			if(!T.count(x) || bitcount(T[x]) < bitcount(i)) T[x] = i;
		}
		
		// ö�ٺ� n2��Ԫ�ص������Ӽ������� T�в���
		int n2 = N - n1;	
		int ans = 0;
		for(int i = 0; i < (1 << n2); i++) {
			int x = 0;
			for(int j = 0; j < n2; j++)  if(i & (1 << j)) x ^= A[n1+j];
			if(T.count(x) && bitcount(ans) < bitcount(T[x]) + bitcount(i)) ans = (i << n1) ^ T[x];
		}
		
		// ������
		cout << bitcount(ans) << endl;
		
		for(int i = 0; i < N; i++) if(ans & (1 << i)) cout << i + 1 << " ";
		cout << endl;
	}	
	
	return 0;
}


/*
Sample Input
1
ABC
6
ABD
EG
GE
ABE
AC
BCD

Sample Output
0

5
1 2 3 5 6



*/
