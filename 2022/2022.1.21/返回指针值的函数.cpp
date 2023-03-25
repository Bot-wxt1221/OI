#include <iostream>
using namespace std;
int *getint1(){
	int value1 = 20;
	return &value1;
}
int main(){
	int *p;
	p = getint1();
	cout <<  *p << endl;
	return 0;
}

