#include <iostream>
using namespace std;
void function(){
	int a = 0;
	static int b = 0;
	a++;
	b++;
	cout<<a<<endl<<b<<endl; 
}
int main(){
	for(int i=1;i<=6;i++){
		function();
		cout<<"--------------"<<endl;
	}
	return 0;
}
/*
fun()µÚÒ»´Î
0x004016b0 <+0>:	push   %ebp
   0x004016b1 <+1>:	mov    %esp,%ebp
   0x004016b3 <+3>:	push   %ebx
   0x004016b4 <+4>:	sub    $0x24,%esp
   0x004016b7 <+7>:	call   0x414850 <mcount>
   0x004016bc <+12>:	movl   $0x0,-0xc(%ebp)
   0x004016c3 <+19>:	addl   $0x1,-0xc(%ebp)
   0x004016c7 <+23>:	mov    0x490028,%eax
   0x004016cc <+28>:	add    $0x1,%eax
   0x004016cf <+31>:	mov    %eax,0x490028
   0x004016d4 <+36>:	mov    0x490028,%ebx
   0x004016da <+42>:	mov    -0xc(%ebp),%eax
   0x004016dd <+45>:	mov    %eax,(%esp)
   0x004016e0 <+48>:	mov    $0x464fa0,%ecx
   0x004016e5 <+53>:	call   0x438de0 <_ZNSolsEi>
   0x004016ea <+58>:	sub    $0x4,%esp
   0x004016ed <+61>:	movl   $0x456340,(%esp)
   0x004016f4 <+68>:	mov    %eax,%ecx
   0x004016f6 <+70>:	call   0x438bf0 <_ZNSolsEPFRSoS_E>
   0x004016fb <+75>:	sub    $0x4,%esp
   0x004016fe <+78>:	mov    %ebx,(%esp)
   0x00401701 <+81>:	mov    %eax,%ecx
   0x00401703 <+83>:	call   0x438de0 <_ZNSolsEi>
   0x00401708 <+88>:	sub    $0x4,%esp
   0x0040170b <+91>:	movl   $0x456340,(%esp)
   0x00401712 <+98>:	mov    %eax,%ecx
   0x00401714 <+100>:	call   0x438bf0 <_ZNSolsEPFRSoS_E>
   0x00401719 <+105>:	sub    $0x4,%esp
   0x0040171c <+108>:	mov    -0x4(%ebp),%ebx
   0x0040171f <+111>:	leave  
   0x00401720 <+112>:	ret     

*/
