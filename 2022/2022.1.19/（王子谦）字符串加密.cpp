#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main () {
	char a [ 1001 ];//����������ַ��� 
	while ( cin.getline ( a, 1001 ) ) {//���в������� 
		int i = 0;
		while ( a [ i ] != '\0' ) {//�������ַ���������������ѭ�� 
			if ( a [ i ] == ' ' ) {//��a [ i ]Ϊ�ո�ʱֱ����� 
				cout << a [ i ];
				i ++;
			}else{//������д��� 
				a [ i ] ++;
				cout << a [ i ];
				i ++;
			}
		}
		cout << endl;
	}
	return 0;
}
