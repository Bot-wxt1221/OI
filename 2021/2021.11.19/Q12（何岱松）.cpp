#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int get(int x){
	int cnt = 0, ans = 0;//cnt����������Ѿ��м������ֳ����ˣ�ans�������Ҫ����λ��Ч���� 
	int t[10] = {0};//����ǵ�ǰ�Ѿ�����Щ���ֳ����ˣ�û���־���0�������˾���1 
	long double y = sqrt((long double)x);//���� 
	while ((int)y / 10 != 0) y /= 10;//�������ֻ��һλ��С����ǰ�� 
	while (y){ 
		if (cnt == 10) break;//����Ѿ��������������˾ͽ��� 
		if (t[(int)y] == 0) cnt++, t[(int)y] = 1;//����������û�г��ֹ� 
		y = y - ((int)y % 10);
		y *= 10;//�����У��������������ǰһλ������֮ǰ�Ǹ���ɾ�� 
		ans++; 
	}
	return ans;
}

int main(){
	int a;
	cin >> a;
	cout << get(a);
}
