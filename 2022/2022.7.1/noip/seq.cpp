#include <iostream>
#include <cstdio>
#include <cmath>
#define int unsigned long long
using namespace std;
int read(){
	char a=getchar();
	int f=1,x=0;
	while(a<'0'||a>'9'){
		(a=='-')?(f=-1):1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=x*10+(a-'0');
		a=getchar();
	}
	return x*f;
}
int cen=0;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	cen+=a/b;
	return gcd(b,a%b);
}
signed main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	int i=read(),j=read();
	gcd(max(i,j),min(j,i));
	cout<<cen+1;
	return 0;
}

