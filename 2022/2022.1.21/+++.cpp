#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int i=1;
	++i;

	i=1;
	i++; 
	return 0;
}
/*»ã±à£º
0x004016c8 <+24>:	movl   $0x1,0xc(%esp) 
0x004016d0 <+32>:	addl   $0x1,0xc(%esp)
0x004016d5 <+37>:	movl   $0x1,0xc(%esp)
0x004016dd <+45>:	addl   $0x1,0xc(%esp)
  */ 
