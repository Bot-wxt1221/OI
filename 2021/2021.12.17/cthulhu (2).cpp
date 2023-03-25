#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
unsigned long long f(int a);
int main(){
    freopen("cthulhu.in","r",stdin);
    freopen("cthulhu.out","w",stdout);
    int t,temp;
    cin>>t;
    for(int i=1;i<=t;i++){
    	cin>>temp;
    	cout<<f(temp)<<' ';
    }
    return 0;
}
unsigned long long f(int a){
	unsigned long long ans=0;
	for(int i=1;i<=a*a;i++){
		long double temp=sqrt(i*i+a*a);
		if(floor(temp)==temp){
			ans++;
		}
	}
	return ans;
}
