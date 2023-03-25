#include <iostream>
#include <cstdio>

using namespace std;
//0 1 0 2 1 0 1 3
int a[20005];
int main(){
	freopen("rain.in","r",stdin);
	freopen("rain.out","w",stdout);
	int Max=0,index=0;int ans=0;
	int k,n,i=0;
	while(cin>>n){
		if(Max<=n){
			Max=n;index=i;
		}
		a[i]=n;
		i++;
	}	
	Max=0;
	for(int j=0;j<=index;j++){
		Max=max(Max,a[j]);
		ans+=Max-a[j];
	}
	Max=0;
	for(int j=i;j>index;j--){
		Max=max(Max,a[j]);
		ans+=Max-a[j];
	}
	cout << ans;
	return 0;
}
