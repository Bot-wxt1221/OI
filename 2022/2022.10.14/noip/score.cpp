#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
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
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a=read(),b=read(),c=read();
	int ans=(a/5)+(b/10)*3+c/2;
	printf("%d",ans);
	return 0;
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



