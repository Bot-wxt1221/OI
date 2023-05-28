#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
void find_sum(int *a,int n,int m){
	sort(a,a+n);
	int l=0,r=n-1;
	while(l<r){
		int sum=a[l]+a[r];
		if(sum>m){
			r--;
		}else if(sum<m){
			l++;
		}
		if(sum==m){
			cout<<a[l]<<' '<<a[r]<<endl;
			l++;
		}
	} 
}
int a[1005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	find_sum(a,n,m);
	return 0;
}
