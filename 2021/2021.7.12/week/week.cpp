#include <iostream>
#include <cstdio>
using namespace std;
long long pow(long long a,long long b){
	if(b==0){
		return 1;
	}
	if(b%2==0){
		long long ans=pow(a,b/2);
		return ans*ans;
	}
	return pow(a,b-1)*a;
}
int main() {
	freopen("week.in","r",stdin);
	freopen("week.out","w",stdout);
	long long a;
	long long b;
	cin>>a>>b;
	a=a%7;
	a=pow(a,b);
	if(a%7==0){
		cout<<7;
		return 0;
	}
	cout<<a%7;
	return 0;
} 
