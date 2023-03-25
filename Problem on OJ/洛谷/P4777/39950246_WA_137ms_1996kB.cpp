#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[100005];
int b[100005];
void exgcd(int a,int b,int &g,int &x,int &y) {
    if (b == 0) {
        g = a;
        x = 1;
        y = 0;
        return;
    }
    exgcd(b,a%b,g,y,x);
    y-=(a/b)*x;
    return ;
}

void china(int &a1,int &b1,int &a2,int &b2){
    int d=a2-a1;
    int g,x,y;
    exgcd(b1,b2,g,x,y);
    if(d%g==0){
        x=(((x*d/g)%(b2/g)+(b2/g)))%(b2/g);
        a1+=x*b1;
        b1=(b1*b2)/g;
    }
    return ;
}
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        b[i]=read();
        a[i]=read();
    }
    for(int i=2;i<=n;i++){
        china(a[1],b[1],a[i],b[i]);
    }
    printf("%lld",a[1]);
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


