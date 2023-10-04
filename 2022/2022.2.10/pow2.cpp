#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define int long long
using namespace std;
long long a,k,p;
int pow(int a,int b,int mod){
	if(b==0){
		return 1;
	}else if(b%2==1){
		return (pow(a,b-1,mod)*a)%mod;
	}else{
		int temp=pow(a,b/2,mod)%mod;
		return temp*temp%mod;
	}
}
signed main(){
//	freopen("pow.in","r",stdin);
//	freopen("pow.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld%lld%lld",&a,&p,&k);
		cout<<pow(a,p,k)<<endl;
	}
	return 0;
}
	
