#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	cout<<&"Hello!"<<endl;
	char *a=(char *)&"Hello!";
//	*a='A';//���������Ļ�ֹͣ���� 
	cout<<a;
	return 0;
}

