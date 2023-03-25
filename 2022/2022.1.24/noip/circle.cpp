#include <iostream>
#include <cstdio>
using namespace std;
int te[1000005];
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
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	long long n,m,k,x,temp,p;
	cin>>n>>m>>k>>x;
	temp=x;
	for(int i=1;i<=n;i++){
		temp=(temp+m)%n;
		te[i]=temp;
		if(te[i]==x){
			p=i;
		}
	}
	if((pow(10,k,n)%n+p)%n==0){
		cout<<te[(pow(10,k,n)%n+p)];
	}else{
		cout<<te[(pow(10,k,n)%n+p)%n];
	}
	return 0;
}

