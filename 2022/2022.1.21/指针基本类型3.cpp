#include <iostream>
using namespace std;
int main(){
	int a = 256,b = 255;
	const int *p = &a;
	//*p = 257;   *p  read-only   p read-and-write
	a = 123; // a read-and-write 
	p = &b;
	cout << *p <<endl;
	return 0;
} 
