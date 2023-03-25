#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	cout<<a*b-a-b;
	return 0;
}

