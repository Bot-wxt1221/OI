#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int f=1,x=0;
	char a=getchar();
	while('0'>a||a>'9'){
		(a=='-')?(f=-1):1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=(x<<3)+(x<<1)+(a^48);
		a=getchar();
	}
	return f*x;
}
int fa[10005];
int a[10005],b[10005];
int a2[10005],b2[10005];
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int n,m;
int solve(int aaa,int baa){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(i!=aaa){
			fa[getfa(a[i])]=getfa(b[i]);
		}
	}
	for(int i=1;i<=m;i++){
		if(i!=baa){
			fa[getfa(a2[i])]=getfa(b2[i]);
		}
	}
	int have=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i){
			have++;
		}
	}
	return have!=1;
}
int main(){
	freopen("yam.in","r",stdin);
	freopen("yam.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<n;i++){
		a[i]=read();
		b[i]=read();
	}
	for(int i=1;i<=m;i++){
		a2[i]=read();
		b2[i]=read();
	}
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			ans+=solve(i,j);
		}
	}
	printf("%d",ans);
	return 0;
}


