#include <iostream>
using namespace std;
int *getint1(){
	int value1 = 20;
	return &value1;
}
int *getint2(){
	int value2 = 30;
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
   0x004016b3 <+3>:	sub    $0x10,%esp
   0x004016b6 <+6>:	call   0x414890 <mcount>
   0x004016bb <+11>:	movl   $0x14,-0x4(%ebp)
   0x004016c2 <+18>:	lea    -0x4(%ebp),%eax
   0x004016c5 <+21>:	leave  
   0x004016c6 <+22>:	ret    
...2()»ã±à£º
   0x004016c7 <+0>:	push   %ebp
   0x004016c8 <+1>:	mov    %esp,%ebp
   0x004016ca <+3>:	sub    $0x10,%esp
   0x004016cd <+6>:	call   0x414890 <mcount>
   0x004016d2 <+11>:	movl   $0x1e,-0x4(%ebp)
   0x004016d9 <+18>:	lea    -0x4(%ebp),%eax
   0x004016dc <+21>:	leave  
   0x004016dd <+22>:	ret    
*/
