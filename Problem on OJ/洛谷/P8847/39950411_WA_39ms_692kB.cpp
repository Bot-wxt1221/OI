#include <iostream>
#include <cstdio>
inline int read();

int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    int a=0,b=0;
    for(int i=1;i<=n;i++){
        int temp=read();
        if(temp==-1){
            a++;
        }else{
            b++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a>b){
            printf("1 ");
            a--;
        }else{
            printf("-1 ");
            b--;
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


