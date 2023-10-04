
#include <cstdio> 
using namespace std;
int main(){
	int n;
	cin>>n;
	long long ans=0;
	for(;n!=0;n=n/2){
		ans=n%2+ans*10;
	}
	cout<<ans;
	return 0;
}
