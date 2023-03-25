#include <iostream>
using namespace std;
int main(){
	long long n,ans=0;
	while(cin>>n){
		while(n>0){
			if(n&1==1){
				ans++;
			}
			n=(n>>1);
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
