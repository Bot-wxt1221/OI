#include <iostream>
#include <cstdio>
using namespace std;
int a[105];
int main(){
	freopen("playcard.in","r",stdin);
	freopen("playcard.out","w",stdout);
	int n,totla=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		totla+=a[i];
	}
	int ans=0;
	totla/=n;
	for(int i=1;i<n;i++){
		if(a[i]!=totla){
			ans++;
			int sum=a[i]+a[i+1];
			a[i]=totla;
			a[i+1]=sum-a[i];
		}
	}
	cout<<ans;
	return 0;
}

