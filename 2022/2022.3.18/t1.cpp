/*
˼·1��̰���㷨��
������i���ˣ�����ʱ����ɵĹ����ǣ�i*b; ��Ϊ���Լ�Ҫ��b[i]������n-i-1����ҲҪ��b[i]

Ϊʹ����ʱ��ԽС��Ӧ����b��ķ��ں��棻��bС�ķ���ǰ�棻

����Ҫ������b��������

*/

#include <iostream>
#include <cstdio> 
#include <algorithm>
using namespace std;
int a[1010];
int main() {
	freopen("t1.in", "r", stdin);
	freopen("t1.out", "w", stdout);
	int n;
	int sum = 0;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);  //��С��������
		for(int i = 0; i < n; i++){
			sum += (n - i) * a[i];   //������n���ˣ���ʱ��Ĺ��� 
		}  //���Լ�Ҫ�� a[i]������ n-i-1����ҲҪ�� a[i]
		cout << sum << endl;	
	} 
	return 0;
}
