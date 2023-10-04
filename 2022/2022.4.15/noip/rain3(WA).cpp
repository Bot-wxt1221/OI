#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

int a[20005];
signed main(){
	freopen("rain.in","r",stdin);
	freopen("rain.out","w",stdout);
	int n=0;
	while(scanf("%lld",&a[++n])==1);//∂¡»Î 
	n--;//…Ò∆Ê 
	int ans=0;
	int i=1;
	while(a[i]<a[i+1])	i++;
//	while(a[n]<a[n-1])	n--;
	i--;
	bool aaa=0;
	while(i<=n){
		i++;
		int ai=i;
		int _min=a[ai];
		ai=i;
		bool aa=0;
		while(a[i+1]<a[i]&&aaa)	i++,aa=1;
		i-=aa;
		ai=i;
		while(a[i+1]<a[ai]&&i<=n){
			i++;
		}
		i++;
		for(int j=ai;j<=i&&j<=n;j++){
			if(_min-a[j]>0)
				ans+=(_min-a[j]);
		}
		aaa=1;
	}
	cout<<ans;
	return 0;
}
