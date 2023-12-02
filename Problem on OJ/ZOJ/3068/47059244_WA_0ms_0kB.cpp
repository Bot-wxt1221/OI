#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
double a[1005];
double b[1005];
int n,k;
double c[1005];
bool check(double mid){
    for(int i=1;i<=n;i++){
        c[i]=a[i]+(-b[i]*mid);
    }
    std::sort(c+1,c+n+1);
    double sum=0;
    for(int i=n;i>=n-k+1;i--){
        sum+=c[i];
    }
    return sum>=0;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    while(scanf("%d%d",&n,&k)!=EOF&&n!=0&&k!=0){
        double l=0,r=0;
        for(int i=1;i<=n;i++){
            a[i]=read();
            r+=a[i];
        }
        for(int i=1;i<=n;i++){
            b[i]=read();
            r+=b[i];
        }
        k=n-k;
        for(int i=1;i<=100;i++){
            double mid=(l+r)/2;
            if(check(mid)){
                l=mid;
            }else{
                r=mid;
            }
        }
        printf("%d\n",int(l*100+0.5));
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


