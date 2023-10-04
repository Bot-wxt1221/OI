#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double a[10005];
bool check(double sa);
int n,k;
signed main(){
	freopen("cable.in","r",stdin);
	freopen("cable.out","w",stdout);
	cin>>n>>k;
	double _max=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		_max+=a[i];
	}
	double l=0,r=_max,mid;
	while(r-l>=0.005){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	
	if(l<1.00)	printf("0.00");
	else	printf("%.2lf",l);
}
bool check(double sa){
	long double ans=0;
	for(int i=1;i<=n;i++){
		ans+=floor(a[i]/sa);
	}
	if(ans>=k){
		return true;
	}
	return false;
}
