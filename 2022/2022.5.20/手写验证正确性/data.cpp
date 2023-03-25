#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
//	freopen(".in","r",stdin);
	srand(time(NULL));
	freopen("sort.in","w",stdout);
	cout<<100000<<endl;
	for(int i=1;i<=100000;i++){
		cout<<rand()<<' ';
	}
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/

