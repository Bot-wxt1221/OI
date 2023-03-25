#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	int _min=20000;
	for(int i=1;i<=3;i++){
		int a,b;
		cin>>a>>b;
		_min=min(double(_min),b*ceil(n/double(a)));
	}
	cout<<_min;
	return 0;
}
