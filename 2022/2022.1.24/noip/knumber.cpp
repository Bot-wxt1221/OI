#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int mod = 200907;
long long pow(long a,long long b){
	if(b==0){
		return 1;
	}else{
		int temp=pow(a,b/2)%mod;
		if(b%2==0)
			return (temp*temp)%mod;
		else{
			return ((temp*temp)*a)%mod;
		}
	}
}
signed main(){
	freopen("knumber.in","r",stdin);
	freopen("knumber.out","w",stdout);
	int ns;
	cin>>ns;
	for(int i=1;i<=ns;i++){
		long long a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if((b-a)==(c-b)){
			cout<<(a + (d - 1) * (b - a))%mod<<endl;
		}else {
			int as=b/a;
			cout<<(a%mod
			 * (pow(as , d - 1) )) % mod<<endl;
		}
	}
	return 0;
}

