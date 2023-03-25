
#include <iostream>
#include <cstdio>
#define int long long
#define mod 100003
using namespace std;
long long pow(long a,long long b){
	if(b==0){
		return 1;
	}else{
		int temp=pow(a,b/2)%mod;
		if(b%2==0)
			return (temp*temp)%mod;
		else{
			return ((temp*temp)*a%mod)%mod;
		}
	}
}
signed main(){
	freopen("prisonbreak.in","r",stdin);
	freopen("prisonbreak.out","w",stdout);
	int m,n,ans;
	cin>>m>>n;
	ans=((pow(m,n)%mod-(m*pow(m-1,n-1))%mod)%mod)%mod;
	if(ans<0){
		ans+=mod;
	}
	cout<<ans;
	return 0;
}

