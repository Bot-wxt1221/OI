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
int a[100005];
int main(){
	freopen("1.out","r",stdin);
//	freopen(".out","w",stdout);
	int i=0;
	while(cin>>a[++i]);
	i--;
	freopen("2.out","r",stdin);
	for(int j=1;j<=i;j++){
		int m=read();
		if(a[j]!=m){
			cout<<j<<' ';
			return 1;
		}
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



