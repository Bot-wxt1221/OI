#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	freopen("bit.in","w",stdout);
	srand(time(NULL));
	for(int i=1;i<=1000;i++){
		cout<<rand()<<endl;
	}
	return 0;
}
