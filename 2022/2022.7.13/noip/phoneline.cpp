#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int read(){
	int f=0,x=1;
	char a=getchar();
	while('0'>a||a>'9'){
		(a=='-')?(x=-1):1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		f=(f<<3)+(f<<1)+(a^48);
		a=getchar();
	}
	return f*x;
}
class node{
	public:
		int a,b,l;
		node();
}a[2005];
bool cmp(node a,node b){
	return a.l<b.l;
}
node::node(){
	a=b=l;
	return ;
}
int fa[1005];
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int main(){
	freopen("phoneline.in","r",stdin);
	freopen("phoneline.out","w",stdout);
	int n=read(),p,k;
	p=read();
	k=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=p;i++){
		a[i].a=read();
		a[i].b=read();
		a[i].l=read();
	}
	stable_sort(a+1,a+p+1,cmp);
	int have=1,ans;
	for(int i=1;i<=p&&have<(n-k-1);i++){
		int fx=getfa(a[i].a),fy=getfa(a[i].b);
		if(fx==fy){
			continue;
		}
		have++;
		ans=a[i].l;
		fa[fx]=fy;
	}
	if(have<(n-k-1))
		printf("-1");
	else
		printf("%d",ans);
		return 0;
}
