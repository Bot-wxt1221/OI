#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int i=1;
	++i=7;
//	i++ = 7; //���� 
	cout<<i<<endl;
	return 0;
}
/*
6�л�ࣺ 
0x004016d7 <+39>:	addl   $0x1,-0xc(%ebp)   ��ͬ++i;
0x004016db <+43>:	movl   $0x7,-0xc(%ebp)   ��ͬi=7;
*/ 
