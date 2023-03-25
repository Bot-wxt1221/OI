#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("bit6.in","r",stdin);
	freopen("bit6.out","w",stdout);
	long long n,ans=0;
	while(cin>>n){
		int use=0;
		while(use<32){
			if(n&1==1){
				ans++;
			}
			n=(n>>1);
			use++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
