#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	long long a,b,c,ans=0;
	cin>>a>>b>>c;
	if(a>b){
		swap(a,b);
	}
	for(int i=0;i<=c/b;i++){
		if((c-i*b)%a){
			continue;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
