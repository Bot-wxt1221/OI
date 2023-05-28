#include <cstdio>
#include <iostream>
using namespace std;
unsigned long long  N;
unsigned long long qpow(unsigned long long a,unsigned long long b){
	if(b==-1) return 0;
	if(b==0) return 1;
	unsigned long long  res=1;
	for(;b;a*=a,b>>=1)if(b&1)res*=a;
	return res;
}
int main(){
	freopen("tap.in","r",stdin);
	freopen("tap.out","w",stdout);
	scanf("%llu",&N);
	printf("%llu",qpow(2,N-2));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
