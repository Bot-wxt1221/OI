#include <iostream>
#include <cstdio>
using namespace std;
double f(double x){
	return x*x*x-5*x*x+10*x-80;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

	int n,m;
	cin>>n;
	for(int i=1;1;i++){//求出区间 
		if(f(i)<=n&&f(i+1)>=n){
			m=i;
			break;
		}
	}
	double r=m,l=m+1,mid=(l+r)/2;
	for(int i=1;i<=100;i++){
		if(f(mid)<=0){
			r=mid;
		}else{
			l=mid;
		}
		mid=(l+r)/2;
	}
	printf("%.8f",mid);
	return 0;
}

