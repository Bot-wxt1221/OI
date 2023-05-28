#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	if(c==EOF){
		return -1;
	} 
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
		if(c==EOF){
		return -1;
	} 
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
		if(c==EOF){
		return -1;
	} 
	}
	return f*x;
}
int _max[20005];
int _max2[20005];
int a[20005];
signed main(){
//	freopen("rain.in","r",stdin);
//	freopen("rain.out","w",stdout);
	int n=0;
	while(scanf("%lld",&a[++n])==1);//¶ÁÈë 
	n--;//ÉñÆæ 
	int ans=0;
	int i=1;
	while(a[i]==0)	i++;
	i--;
	while(i<=n){
		int _max=0,lot=0,no=0;
		while(a[i]>=a[i+1]&&i<=n){
			lot++;
			_max=max(_max,a[i]);
			no-=a[i];
			i++;
		}
		while(a[i]<=a[i+1]&&i<=n){
			lot++;
			_max=max(_max,a[i]);
			no-=a[i];
			i++;
		}
		ans+=(_max*lot-no);
	}
	cout<<ans;
	return 0;
}
