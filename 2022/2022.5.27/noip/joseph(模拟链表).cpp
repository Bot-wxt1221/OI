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
int data[10005];
int nxt[10005];
int main(){
	freopen("joseph.in","r",stdin);
	freopen("joseph.out","w",stdout);
	int n,m;
	n=read();m=read();
	for(int i=1;i<=n;i++){
		data[i]=i;
		nxt[i-1]=i;
	}
	nxt[n]=1;
	int now=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			now=nxt[now];
		}
		cout<<data[nxt[now]]<<' ';
		nxt[now]=nxt[nxt[now]];
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


