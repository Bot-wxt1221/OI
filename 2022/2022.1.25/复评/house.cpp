#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int check(int b);
int n,m,c=0,l1;
int a[100005];
int main(){
	freopen("house.in","r",stdin);
	freopen("house.out","w",stdout);
	cin>>l1>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=l1;
	sort(a+1,a+n+1);
	int l=0,r=l1,t,ans;
	while(l<=r){
		int mid=(l+r)/2;
		int num=check(mid);
		if(num>m){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<r;
	return 0;
}
int check(int b){
	int cnt=0,last=0;
	for(int i=1;i<=n;i++){
		if(a[i]-a[last]<b){
			cnt++;
		}else{
			last=i;
		}
	}
	return cnt;
}
