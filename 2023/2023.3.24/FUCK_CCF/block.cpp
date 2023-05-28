#include <iostream>
#include <cstdio>
#define int long long
inline int read();

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	#endif
    int n=read(),m,h,a;
	m=read();
	h=read();
	a=read();
	int ans=1;
	if(n%a==0){
		ans*=(n/a);
	}else{
		ans*=(n/a+1);
	}
	if(m%a==0){
		ans*=(m/a);
	}else{
		ans*=(m/a+1);
	}
	if(h%a==0){
		ans*=(h/a);
	}else{
		ans*=(h/a+1);
	}
	printf("%lld",ans);
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


