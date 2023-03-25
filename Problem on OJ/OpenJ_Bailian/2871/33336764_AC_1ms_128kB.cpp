#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[15];
int b[15];
int c[15];
bool cmp(int a,int b){
	return a>b;
}
void work(){
	int as=0,bs=0;
	for(int i=0;i<10;i++){
		int bb=c[i];		
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
	cout<<endl;
}
int main(){
	while(cin>>c[0]){
		cin>>c[1]>>c[2]>>c[3]>>c[4]>>c[5]>>c[6]>>c[7]>>c[8]>>c[9];
		work();
	}
	return 0;
}