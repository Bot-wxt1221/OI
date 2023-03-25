#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("divide.in","r",stdin);
	freopen("divide.out","w",stdout);
	int a,b;
	cin>>a>>b;
	printf("%d/%d=%d.",a,b,a/b);
	int more=a%b;
	for(int i=1;i<=20;i++){
		cout<<more*10/b;
		more=(more*10)%b;
	}
	return 0;
}

