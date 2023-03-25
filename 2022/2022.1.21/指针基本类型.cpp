#include <iostream>
using namespace std;
int main(){
	int a = 256;
	int *p= &a;
	*p = 257;
	cout << *p <<endl;
	return 0;
} 
