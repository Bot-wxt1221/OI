#include <iostream>
#include <cstdio> 
using namespace std;
int abc(int n);
int main(){
	int n;
	cin>>n;
	cout<<abc(n);
	return 0;
}
int abc(int n){
	if(n==0){
		return 0;
	}
	return abc(n/2)*10+n%2;
}
