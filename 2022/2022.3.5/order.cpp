/*
时间最小的先进行 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005];
int main(){
	freopen("order.in","r",stdin);
	freopen("order.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=(a[i]*(n-i+1)); 
	}
	printf("%.2lf",double(ans)/n);
	return 0;
}

