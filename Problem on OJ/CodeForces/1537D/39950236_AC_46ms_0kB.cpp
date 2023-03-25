#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();

int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int T=read();
    while(T--){
        int n=read();
        if(n%2==1){
            printf("Bob\n");
        }else{
            int lg=log2(n);
            if((1<<lg)!=n){
                printf("Alice\n");
            }else if(lg%2==1){
                printf("Bob\n");
            }else{
                printf("Alice\n");
            }
        }
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
