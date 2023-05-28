#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define data 5
using namespace std;
int main(){
//	freopen(".in","r",stdin);
	srand(time(NULL));
	freopen("fence.in","w",stdout);
	cout<<data<<endl;
	for(int i=1;i<=data;i++){
		cout<<rand()%10+1<<' ';
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

