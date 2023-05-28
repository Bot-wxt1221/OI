#include <iostream>
#include <cstdio>
#define int long long
inline int read();

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("div.in","r",stdin);
	freopen("div.out","w",stdout);
	#endif
    int n=read();
    if(n%2){
        printf("%lld",(n/2)*6+1);
    }else{
        printf("%lld",(n/2)*6-1);
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


