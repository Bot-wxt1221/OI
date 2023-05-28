#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();
int n,f;
const long double PI=acos(-1);
int r[10005];
int check(long double s){
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=floor(r[i]/s);
    }
    return ans;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int T=read();
    while(T--){
        n=read();
        f=read();
        for(int i=1;i<=n;i++){
            r[i]=read();
            r[i]*=r[i];
        }
        long double l=0,r=100000010;
        while(r-l>1e-7){
            long double mid=(l+r)/2;
            if(check(mid)>f){
                l=mid;
            }else{
                r=mid;
            }
        }
        printf("%.4Lf\n",l*PI);
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


