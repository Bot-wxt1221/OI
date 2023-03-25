#include <iostream>
#include <cstdio>
#include <complex>
#include <cmath>
#define int long long
inline int read();
const double Pi=acos(-1.0);
struct complex
{
    double real,y;
    complex (double xx=0,double yy=0){real=xx,y=yy;}
};
complex operator + (complex a,complex b){ return complex(a.real+b.real , a.y+b.y);}
complex operator - (complex a,complex b){ return complex(a.real-b.real , a.y-b.y);}
complex operator * (complex a,complex b){ return complex(a.real*b.real-a.y*b.y , a.real*b.y+a.y*b.real);}
complex f[8000005],g[8000005],ans[8000005];
int r[8000005];
void fft(complex *f,int limit,int type);
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("P3803_2.in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    for(int i=0;i<=n;i++){
        f[i].real=read();
    }
    for(int i=0;i<=m;i++){
        g[i].real=read();
    }
    if(n==0){
        for(int i=0;i<m;i++){
            printf("%lld ",g[i].real*f[0].real);
        }
        return 0;
    }
    if(m==0){
        for(int i=0;i<n;i++){
            printf("%lld ",f[i].real*g[0].real);
        }
        return 0;
    }
    int limit=1,k=0;
    while(limit<(n+m)){
        limit=(limit)<<1;
        k++;
    }
    for(int i=0;i<=limit;i++){
        r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));
    }
    fft(f,limit,1);
    fft(g,limit,1);
    for(int i=0;i<=limit;i++){
        f[i]=f[i]*g[i];
    }
    fft(f,limit,-1);
    for(int i=0;i<=n+m;i++){
        printf("%lld ",(int)(f[i].real/(limit)+0.5));
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
void fft(complex *f,int limit,int type){
    for(int i=0;i<=limit;i++){
        if(i<r[i]){
            std::swap(f[i],f[r[i]]);
        }
    }
    for(int length=2;length<=limit;length=(length<<1)){
        complex  Wn (std::cos(Pi*2/length),std::sin(type*Pi*2/length));
        for(int i=0;i<=limit;i+=length){
            complex  wn1(1,0);
            for(int k=i;k<length/2+i;k++,wn1=wn1*Wn){
                complex x=f[k],y=f[k+length/2]*wn1;
                f[k]=x+y;
                f[k+length/2]=x-y;
            }
        }
    }
    return ;
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


