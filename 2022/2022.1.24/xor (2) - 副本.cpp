#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,ans;
	cin>>a>>ans;
	for(int i=2;i<=a;i++){
		int temp;
		cin>>temp;
		ans=ans^temp;
	}
	cout<<ans;
	return 0;
}

