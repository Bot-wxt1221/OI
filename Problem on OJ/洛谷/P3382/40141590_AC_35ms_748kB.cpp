#include <iostream>
#include <cstdio>
using namespace std;
inline int read();
double l,r;
double a[20];
int n;
double f(double x){
    double ans=0;
    for(int i=n;i>=0;i--){
        ans*=x;
        ans+=a[i];
    }
    return ans;
}
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    n=read();
    scanf("%lf%lf",&l,&r);
    for(register int i=n;i>=0;i--){
        scanf("%lf",&a[i]);
    }
    for(register int i=1;i<=100;i++){
        double mid3=(r-l)/3;
        double mid1=l+mid3,mid2=r-mid3;

        if(f(mid1)<f(mid2)){
            l=mid1;
        }else{
            r=mid2;
        }
    }
    // f(-0.41421);
    printf("%lf",l);
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

