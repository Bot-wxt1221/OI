#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	int p=0;
	while(n>1){
		if(m*2<n)n-=m;
		else n-=n/2;
		p++;
	}
	cout<<p;
}
