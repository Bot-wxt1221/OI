#include <iostream>
#include <cstdio>
inline int read();
int a[255];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("CBT.in","r",stdin);
	freopen("CBT.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        printf("node %d: key = %d, ",i,a[i]);
        if(i!=1){
            printf("parent key = %d, ",a[i/2]);
        }
        if(i*2<=n){
            printf("left key = %d, ",a[i*2]);
        }
        if(i*2+1<=n){
            printf("right key = %d, ",a[i*2+1]);
        }
        printf("\n");
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


