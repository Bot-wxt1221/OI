#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int dp[500005];
int f[500005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("lic.in","r",stdin);
	freopen("lic.out","w",stdout);
	#endif
    int n=read();
    int _max=0;
    for(int i=1;i<=n;i++){
        int a=read();
        if (a>=f[_max]) {f[++_max]=a; continue;}
        int l=0,r=_max+1; while(r-l>1){
            int m=l+(r-l)/2;
            if(f[m]<=a) l=m; else r=m;
        }
        f[l+1]=std::min(f[l+1],a);
    }
    printf("max=%d",_max);
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

