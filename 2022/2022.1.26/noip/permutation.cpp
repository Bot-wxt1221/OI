#include <iostream>
#include <cstdio>
#define mod 1234567
using namespace std;
long long pow(long long a,long long b){
	if(b==0){
		return 1;
	}
	if(b%2==1){
		return pow(a,b-1)*a%mod;
	}else{
		long long temp=pow(a,b/2);
		return temp*temp%mod;
	}
}
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	long long n,ans;
	scanf("%lld",&n);
	printf("%lld",pow(2,n-1)%mod);
}

