#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int x[50005];
int a[500005];
int b[500005];
int c[500005];
int ans[500005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        x[i]=read();
    }
    int m=1;
    while(scanf("%lld%lld%lld",&a[m],&b[m],&c[m])!=EOF){
    	m++;
	}
	m--;
    int la=0-c[m];
    ans[m-1]=la;
    for(int i=m-2;i>=1;i--){
        int y=(la)*(x[la]);
        int z=(la+1)*(x[la])*(x[la]);
        ans[i]=-c[i+1]-la-((b[i+1]+1)*y)-(a[i+1]*z);
        ans[i]/=z+y+1;
        la=ans[i];
    }
    for(int i=1;i<=m-1;i++){
        printf("%lld\n",ans[i]);
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


