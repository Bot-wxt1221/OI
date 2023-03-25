#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int a[10005];
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
} 
