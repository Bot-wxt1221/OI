/*
˼·2��̰���㷨+�������������ˣ�

�������������ˣ��������ǵ�ʱ����b[x]��b[y];

���x��ǰ�棬������2*b[x]+b[y]

���y��ǰ�棬������2*b[y]+b[x] 
 
���߱Ƚϣ�С����ǰ��

*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(const int &a,const int &b){//�Ƚ����������� 
	return 2 * a + b < 2 * b + a;
} //a��ǰ��������Ҫ��ʱ�䣺a+(a+b)
  //b��ǰ��������Ҫ��ʱ��: b+(b+a) 

int main() {
	freopen("t1.in", "r", stdin);
	freopen("t1.out", "w", stdout);
	int a[1001];
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n, cmp);
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += (n - i) * a[i];
		}
		cout << sum << endl;
	}
	return 0;
}
