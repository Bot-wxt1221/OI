#include <iostream>
using namespace std;
int k = 0, n;
void mov(int n, char a, char c, char b);   //��b����ΪЭ�����ɣ���a���ϵģ�n���Ƶ�c����

int main() {
	cout << "n=";
	cin >> n;
	mov(n, 'a', 'c', 'b'); 
	
	return 0;
}
void mov(int n, char a, char c, char b) {  //��b����ΪЭ�����ɣ���a���ϵģ�n���Ƶ�c����
	if (n == 0) return;            //���n=0�����˳�������������
	mov(n - 1, a, b, c);            //��c����ΪЭ�����ɣ���a���ϵģ�n-1��Ƭ�Ƶ�b����
	k++;
	cout << k << " :from " << a << "-->" << c << endl;
	mov(n - 1, b, c, a);             //��a����ΪЭ�����ɣ���b���ϵģ�n-1���Ƶ�c����
	
	return;
}
