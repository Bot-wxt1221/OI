#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;
int a[1005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int s=m-a[i];
		int l=1,r=n,mid=(l+r)/2;
	   	while(l<r){
			if(a[mid]<=s){
				l=mid;
			}else{
				r=mid-1;
			}
			mid=(l+r+1)/2;
		}
		if(a[mid]==s&&mid>i){
			cout<<a[i]<<' '<<a[mid]<<endl;
		}
	}
	return 0;
}

