#include <iostream>
#include <cstdio>
#include <algorithm>
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
int fa[40005];
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
class node{
	public:
		int a,b,c;
}a[100005];
bool cmp(node a,node b){
	return a.c>b.c;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n*2;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		a[i].a=read();
		a[i].b=read();
		a[i].c=read();
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(getfa(a[i].a)==getfa(a[i].b)){
			printf("%d",a[i].c);
			return 0;
		}
		fa[getfa(a[i].a)]=fa[getfa(a[i].b+n)];
		fa[getfa(a[i].a+n)]=fa[getfa(a[i].b)];
	}
	cout<<0;
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

