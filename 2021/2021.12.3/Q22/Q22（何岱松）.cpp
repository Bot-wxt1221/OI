#include <cstdio>
#include <iostream>
using namespace std;

int a[105] = {1, 0, 1, 0, 2, 0, 5};
//һ��ʼ��0����Ҳ��1�ַ�����Ϊ��֮����� 
int f(int x){
	if(a[x] != 0) return a[x];//����Ѿ������� 
	int ans = 0;//�ж����ַ��� 
	for(int i = 0; i <= x - 2; i += 2){
	//�����Ѿ���һ�������Ѿ��̶�����ô��������ͱ������߷�Ϊ�������֣�ÿ�����ַֿ��㣬�ٳ����� 
		ans += f(i) * f(x - 2 - i);
	}
	a[x] = ans; //��¼��ǰ�Ľ�� 
	return ans;
}

int main(){
	int n;cin >> n;
	cout << f(n);
}
