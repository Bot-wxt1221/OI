#include <iostream>
#include <cstdio>
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
int a[1000005];
int main(){
	freopen("ST.in","r",stdin);
	freopen("1.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int m=read();
	for(int i=1;i<=m;i++){
		int aa=read();
		int b=read();
		int _max=-10000;
		for(int j=aa;j<=b;j++){
			_max=max(_max,a[j]);
		}
		printf("%d\n",_max);
	}
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



