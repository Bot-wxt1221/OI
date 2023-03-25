#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();

int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("vote.in","r",stdin);
	freopen("vote.out","w",stdout);
	#endif
    int a=read(),b,k;
    b=read();
    k=read();
    int out1=0,out2=0;
    long double ans=k+2;
    for(int i=0;i<=k;i++){
        for(int j=1;j<=k;j++){
            if((long double)(i)/j>=(long double)(a)/b){
                if(ans>(long double)(i)/j-(long double)(a)/b){
                    ans=(long double)(i)/j-(long double)(a)/b;
                    if(std::__gcd(i,j)==1){
                        out1=i;
                        out2=j;
                    }
                }
            }
        }
    }
    printf("%d %d",out1,out2);
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


