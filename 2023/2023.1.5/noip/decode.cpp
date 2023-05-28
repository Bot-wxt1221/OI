#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char que[100000005];
int l=1,r=0;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	#endif
    scanf("%s",que+1);
    int str=strlen(que+1);
    r=str;
    while(l<=r){
        putchar(que[l++]);
        que[++r]=que[l++];
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


