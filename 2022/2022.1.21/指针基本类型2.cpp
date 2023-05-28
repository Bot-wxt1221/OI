#include <iostream>
using namespace std;
int main(){
	int a = 256;
	const int *p = &a;
	//*p = 257;   *p  read-only p read-and-write
	a = 123; // a read-and-write 
	cout << *p <<endl;
	return 0;
} 
