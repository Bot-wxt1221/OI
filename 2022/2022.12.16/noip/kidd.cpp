#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
inline int read();
int f[500005];
int a[500005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("kidd.in","r",stdin);
	freopen("kidd.out","w",stdout);
	#endif
    int t=read();
    while(t--){
        memset(f,0,sizeof(f));
        f[0]=0x3f3f3f3f;
        int n=read();
        int _max=0;
        for(int i=1;i<=n;i++){
            int a=read();
            ::a[i]=a;
            if (a<f[_max]) {f[++_max]=a; continue;}
            int l=0,r=_max+1; while(r-l>1){
                int m=l+(r-l)/2;
                if(f[m]>a) l=m; else r=m;
            }
            f[l+1]=std::max(f[l+1],a);
        }memset(f,0,sizeof(f));
        int _max2=0;
        for(int i=1;i<=n;i++){
            int a=::a[i];
            if (a>f[_max2]) {f[++_max2]=a; continue;}
            int l=0,r=_max2+1; while(r-l>1){
                int m=l+(r-l)/2;
                if(f[m]<a) l=m; else r=m;
            }
            f[l+1]=std::min(f[l+1],a);
        }
        printf("%d\n",std::max(_max,_max2));
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

