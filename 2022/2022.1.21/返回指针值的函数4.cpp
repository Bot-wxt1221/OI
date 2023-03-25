#include <iostream>
using namespace std;
int *getint1(){
	static int value1 = 20;//¾²Ì¬ 
	return &value1;
}
int *getint2(){
	static int value2 = 30;//¾²Ì¬ 
	return &value2;
}
int main(){
	int *p ,*q;
	p = getint1();
	cout << *p << endl;
	q = getint2();
	cout << p << ' ' << *p << endl;
	cout << q << ' ' << *q << endl;
	return 0;
}
/*
...1()»ã±à£º
   0x004016b0 <+0>:	push   %ebp
   0x004016b1 <+1>:	mov    %esp,%ebp
   0x004016b3 <+3>:	call   0x414880 <mcount>
   0x004016b8 <+8>:	mov    $0x45f000,%eax
   0x004016bd <+13>:	pop    %ebp
   0x004016be <+14>:	ret     
...2()»ã±à£º
   0x004016bf <+0>:	push   %ebp
   0x004016c0 <+1>:	mov    %esp,%ebp
   0x004016c2 <+3>:	call   0x414880 <mcount>
   0x004016c7 <+8>:	mov    $0x45f004,%eax
   0x004016cc <+13>:	pop    %ebp
   0x004016cd <+14>:	ret        
*/
