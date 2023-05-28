#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main(){
//	freopen("safe.in","r",stdin);
//	freopen("safe.out","w",stdout);
	float r;
	cin>>r;
	long long ans=0;
	int k=floor(r);
	for(int i=1;i<=k;i++){
		ans=ans+floor(sqrt(r*r-i*i));
	}
	cout<<ans*4;
}
