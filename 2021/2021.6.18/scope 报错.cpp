#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	int a;
	
	{
		int b;
		{
			int c;
			a=0;b=0;c=0;//d=0;
		}
		a=0;b=0;//c=0;d=0;
	}
	{
		int d;
		a=0;/*b=0;c=0;*/d=0;
	}
	a=0;//b=0;c=0;d=0;
	return 0;
}
