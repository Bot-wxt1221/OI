//递推 
#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long MAX=-1;
unsigned long long n3[65],n4[65];//n3表示三塔问题  n4表示四塔问题 
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	int n;
	cin>>n;
	n3[1]=1;
	n4[1]=1;
	for(int i=2;i<=n;i++){
		n3[i]=n3[i-1]*2+1;
	}
	for(int i=2;i<=n;i++){
		unsigned long long temp=MAX;
		for(int j=1;j<=i-1;j++){
			temp=min(temp,2*n4[j]+n3[i-j]);
		}
		n4[i]=temp;
	}
	cout<<n4[n];
	return 0;
}

