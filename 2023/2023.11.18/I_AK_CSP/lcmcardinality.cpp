#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("lcmcardinality.in","r",stdin);
	freopen("lcmcardinality.out","w",stdout);
	#endif
    int n;
	while((n=read())!=0){
		printf("%lld ",n);
		int sq=sqrt(n);
		int ans=1;
		for(int i=2;i<=sq;i++){
			if(n%i==0){
				int cnt=0;
				while(n%i==0){
					n=n/i;
					cnt++;
				}
				ans*=cnt*2+1;
			}
		}
		if(n!=1){
			ans*=3;
		}
		printf("%lld\n",ans/2+1);
	}
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


