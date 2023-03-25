#include <iostream>
#include <cstdio>
using namespace std;
long long pow(long long b,long long p,long long k);
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	long long b,p,k;
	cin>>b>>p>>k;
	printf("%lld^%lld mod %lld=%lld",b,p,k,pow(b,p,k));
	return 0;
}
long long pow(long long b,long long p,long long k){
	if(p==0){
		return 1LL;
	}
	if(p%2==0){
		long long temp=pow(b,p/2,k)%k;
		return temp*temp%k; 
	}else{
		return pow(b,p-1,k)*b%k;
	}
}
