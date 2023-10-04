#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
signed main(){
	freopen("snow.in","r",stdin);
	freopen("snow.out","w",stdout);
	int x1,y1,x2,y2;
	scanf("%lld%lld",&x1,&y1);
	double ans=0;
	while(scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2)!=EOF){
		int a=abs(x1-x2);
		int b=abs(y1-y2);
		ans+=sqrt(a*a+b*b); 
	}
	ans=ans*2;
	long long h=ans/1000/20;
	long long temp=(ans-h*20000)*3;
	long long m=0;
	if(temp%1000>=500){
		m=temp/1000+1;
	}else{
		m=temp/1000;
	}
	if(m<10){
		printf("%lld:0%lld",h,m);
	}else
		printf("%lld:%lld",h,m);
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/

