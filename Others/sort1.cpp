#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio> 
using namespace std;
int main(){
	freopen("sort.in","w",stdout);
	cout<<90000<<endl;
	srand(time(NULL));
	for(int i=1;i<=90000;i++){
		long long temp;
		for(int i;i<=rand();i++){
			temp=temp+rand();
		}
		cout<<temp<<endl;
	}
	return 0;
}
