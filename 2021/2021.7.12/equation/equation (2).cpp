#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	int a,b,c,x1,y1,x2,y2;
	cin>>a>>b>>c;
	for(int i=0;i<=c/a;i++){
		if((c-i*a)%b){
			continue;
		}
		x1=i;
		y1=(c-i*a)/b;
		break;
	}
	for(int i=c/a;i>=0;i--){
		if((c-i*a)%b){
			continue;
		}
		x2=i;
		y2=(c-i*a)/b;
		break;
	}
	cout<<__gcd(abs(x1-x2),abs(y1-y2))+1;
	return 0;
}
