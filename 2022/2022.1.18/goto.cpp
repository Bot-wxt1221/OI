#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int i=0,sum=0;
	i=1;
	loop:
		sum=sum+i;
		i++;
		if(i<=100)
			goto loop;
		cout<<sum<<endl;
		return 0;
}
