#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int read(){
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
int n,m;

int a[10006];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n+m;i++){
		a[i]=read();
	}
	reverse(a+1,a+n+m+1);
	reverse(a+1,a+m+1);
	reverse(a+m+1,a+n+m+1);
	for(int i=1;i<=n+m;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
/*
Anything about this program:
Type:
	例题 
Description:
	将{a1,a2,...,an,b1,b2,...,bm}
	原地置换为{b1,b2,...,bm,a1,a2,...,an} 
Example:
	1:
		In:
			1 2
			1 2 3
		Out:
			2 3 1
More:

*/

