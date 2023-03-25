#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int a[10005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,temp=0,last=1;
	cin>>n;
	for(int i=1;temp<=n;i++){
		for(int j=1;j<=i;j++){
			a[++temp]=last;
		}
		last++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
