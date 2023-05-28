#include <iostream>
#include <cstdio>
#include <vector> 
using namespace std;
vector <int> a;
int main(){
	cout<<2<<" ";//众所周知 2是质数 
	a.push_back(2);
	for(int i=3;i<=100;i+=2){// 除开 2外后，没有是偶数的质数 
		bool y=1;
		for(int j=0;j<a.size()&&a[j]*a[j]<=i;j++){//若一个数能被 a整除，则一定能被 a的所有质因数整除 
			if(i%a[j]==0){
				y=0;
			}
		}
		if(y){
			a.push_back(i);
			cout<<i<<' ';
		}
	}
	return 0;
}

