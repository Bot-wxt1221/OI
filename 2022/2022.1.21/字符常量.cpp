#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	cout<<&"Hello!"<<endl;
	char *a=(char *)&"Hello!";
//	*a='A';//常量区更改会停止工作 
	cout<<a;
	return 0;
}

