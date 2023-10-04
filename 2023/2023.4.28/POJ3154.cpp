#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();

int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        double ans=0;
        for(int i=1;i<=n;i++){
            double go=((double)i)/n*(n+m);
            ans+=fabs(go-floor(go+0.5))/(n+m);
        }
        printf("%.4lf\n",ans*10000);
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


