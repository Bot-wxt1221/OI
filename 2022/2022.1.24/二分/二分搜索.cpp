
#include <iostream>
#include <cstdio>
#define MAXN 150005
using namespace std;
int a[MAXN+5][2];
bool check(int mid);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,_max=0;
	cin>>n;
	for(int i=1;i=n;i++){
		cin>>a[i][0]>>a[i][1];
		_max=max(_max,a[i][1]);
	}
	int l=1,r=_max,mid=(l+r)/2;
	while(l<r){
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
		mid=(l+r)/2;
	}
	cout<<mid;
	return 0;
}
bool check(int mid){
	
}
