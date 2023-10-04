#include <iostream>
#include <cstdio>
#define int long long
inline int read();

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("chocolate.in","r",stdin);
	freopen("chocolate.out","w",stdout);
	#endif
    int n=read(),m,k;
    m=read();
    k=read();
    int anss=(n)*(m)*(k);
    int ans1=0;
    while(n>1){
        ans1++;
        if(n%2==1){
            n=n/2;
            n++;
        }else{
            n=n/2;
        }
    }
    int ans2=0;
    while(m>1){
        ans2++;
        if(m%2==1){
            m=m/2;
            m++;
        }else{
            m=m/2;
        }
    }
    int ans3=0;
    while(k>1){
        ans3++;
        if(k%2==1){
            k=k/2;
            k++;
        }else{
            k=k/2;
        }
    }
    printf("%lld\n%lld",anss-1,ans1+ans2+ans3);
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


