#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[15];
int b[15];
bool cmp(int a,int b){
	return a>b;
}
void work(){
	int n=10,as=0,bs=0;
	for(int i=2;i<=n;i++){
		int bb;
		cin>>bb;
		if(bb%2==1){
			a[++as]=bb;
		}else{
			b[++bs]=bb;
		}
	}
	sort(a+1,a+as+1,cmp);
	sort(b+1,b+bs+1);
	for(int i=1;i<=as;i++){
		printf("%d ",a[i]);
	}
	for(int i=1;i<=bs;i++){
		printf("%d ",b[i]);
	}
}
int main(){
	while(cin>>a[1]){
		work();
	}
	return 0;
}