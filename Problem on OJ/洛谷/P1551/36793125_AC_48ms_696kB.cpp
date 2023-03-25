#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN=10000;
int fa[MAXN];
int siz[MAXN];
int find(int x); 
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
	int n,m,q;
	n=read();
	m=read();
	q=read();
	for(int i=0;i<n;i++){
		fa[i]=i;
		siz[i]=0;
	}
	int x,y;
	for(int i=0;i<m;i++){
		int n,m; 
		x=read();
		y=read();
		n=find(x);
		m=find(y);
		if(siz[m]<siz[n]){
			swap(n,m);
		}
		//siz[m]>siz[n]
		fa[n]=m;
		siz[m]=max(siz[m],siz[n]+1);
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		if(find(x)==find(y)){
			printf("Yes\n");
			continue;
		}
		printf("No\n");
	}
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
