#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a,int b);
int n[1000];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>n[i];
	}
	sort(n+1,n+a+1,cmp);
	for(int i=1;i<=a;i++){
		cout<<n[i]<<' ';
	}
	cout<<endl;
	while(prev_permutation(n+1,n+a+1)){
		for(int i=1;i<=a;i++){
			cout<<n[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
bool cmp(int a,int b){
	return a>b;
}
