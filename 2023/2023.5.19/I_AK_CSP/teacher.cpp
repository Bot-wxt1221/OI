#include <iostream>
#include <cstdio>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
inline int read();
int a[10000005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("teacher.in","r",stdin);
	freopen("teacher.out","w",stdout);
	#endif
    int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=n-1;i>=1;i--){
		a[i]-=a[i+1];
	}
	int _max1=-inf,_max2=-inf,_max3=-inf;
	for(int i=1;i<=n;i++){
		if(a[i]>=_max1){
			_max3=_max2;
			_max2=_max1;
			_max1=a[i];
		}else if(a[i]>=_max2){
			_max3=_max2;
			_max2=a[i];
		}else if(a[i]>=_max3){
			_max3=a[i];
		}
	}
	printf("%lld %lld %lld",_max1,_max2,_max3);
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


