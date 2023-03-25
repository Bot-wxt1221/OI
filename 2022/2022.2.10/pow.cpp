#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
long long a,k;
char p[100005];
long long mod(char *,long long k);
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
long long init();
int main(){
//	freopen("pow.in","r",stdin);
//	freopen("pow.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld%s%lld",&a,&p,&k);
		long long ans=pow(a,mod(p,init()),k);
		ans%=k;
		cout<<ans<<endl;
	}
	return 0;
}
long long mod(char *a,long long k){
	long long size=strlen(a);
	long long m=0;
	for(int i=0;i<size;i++){
		m=(a[i]+m)%k;
	}
	return m;
}
long long init(){
	long long ans=1;
	long long temp=a;
	for(ans=2;;ans++){
		temp*=a;
		temp%=k;
		if(temp==a){
			break;
		}
	}
	return ans-1;
}
