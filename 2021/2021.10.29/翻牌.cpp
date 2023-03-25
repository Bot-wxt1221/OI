#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	n=floor(sqrt(n));
	for(int i=1;i<=n;i++){
		cout<<i*i<<" ";
	}
	return 0;
}
