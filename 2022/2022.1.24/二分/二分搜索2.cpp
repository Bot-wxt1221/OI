#include <iostream>
#include <cstdio>
#define MAXN 1000
using namespace std;
int a[MAXN+5];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s;
	cin>>s;
	int l=1,r=n,mid=(l+r)/2;
   	while(l<r){
		if(a[mid]<=s){
			l=mid;
		}else{
			r=mid-1;
		}
		mid=(l+r+1)/2;
	}
	cout<<mid;
	return 0;
}

