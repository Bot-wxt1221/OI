#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
bool check(int b);
int n,c,_max=0;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		_max=max(_max,a[i]);
	}
	sort(a+1,a+n+1);
	int l=0,r=_max,mid=(l+r)/2;
	while(r-l>1){
		mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<check(10);
	return 0;
}
bool check(int b){
	int sum=0;
	int l=a[0];
	sum++;
	for(int i=2;i<=n;i++){
		if(a[i]-l<b)	continue;
		l=a[i];
		sum++;
	}
	if(sum>=c){
		return true;
	}
	return false;
}