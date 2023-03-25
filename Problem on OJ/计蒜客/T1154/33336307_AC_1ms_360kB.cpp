#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
double a[45];
double b[45];
bool cmp(double a,double b){
	return a>b;
}
int main(){
	int n,as=0,bs=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		string aa;
		double bb;
		cin>>aa;
		cin>>bb;
		if(aa=="male"){
			a[++as]=bb;
		}else{
			b[++bs]=bb;
		}
	}
	sort(a+1,a+as+1);
	sort(b+1,b+bs+1,cmp);
	for(int i=1;i<=as;i++){
		printf("%.2f ",a[i]);
	}
	for(int i=1;i<=bs;i++){
		printf("%.2f ",b[i]);
	}
}