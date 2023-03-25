#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
using namespace std;
int read(){
	int n;
	scanf("%d",&n);
	return n;
}

signed main(){
//	freopen("math.in","r",stdin);
//	freopen("math.out","w",stdout);
	int t;
	t=read();
	for(int T=1;T<=t;T++){
		int x,z,y=1;
		x=read();
		z=read();
		int d=sqrt(__gcd(x*x,z/x));
		if(d==0||(x/d)==0){
			cout<<-1<<endl;
			continue;
		}
		int q=z/(x*d);
		y=q*d;
		if(x*y*__gcd(x,y)==z){
			cout<<y<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
