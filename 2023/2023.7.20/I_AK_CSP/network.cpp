#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int x=0,op=1;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		op=((temp=='-')?-1:1);
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return x*op;
}
namespace tree{
	int fir[100005];
	int nxt[200005];
	int v[200005];
	int dep[100005];
	int jmp[100005][25];
	int now;
	void add(int x,int y){
		now++;
		v[now]=y;
		nxt[now]=fir[x];
		fir[x]=now;
		return ;
	}
};
void dfs(int now,int fa){
	tree::dep[now]=tree::dep[fa]+1;
	tree::jmp[now][0]=fa;
	for(int i=1;i<25;i++){
		tree::jmp[now][i]=tree::jmp[tree::jmp[now][i-1]][i-1];
	}
	for(int i=tree::fir[now];i!=-1;i=tree::nxt[i]){
		if(tree::v[i]==fa){
			continue;
		}
		dfs(tree::v[i],now);
	}
	return ;
}
int lca(int x,int y){
	if(tree::dep[x]>tree::dep[y]){
		std::swap(x,y);
	}
	while(tree::dep[y]>tree::dep[x]){
		int i;
		for(i=24;i>0;i--){
			int jy=tree::jmp[y][i];
			if(tree::dep[jy]>tree::dep[x]){
				break;
			}
		}
		y=tree::jmp[y][i];
	}
	while(x!=y){
		int i;
		for(i=24;i>0;i--){
			if(tree::jmp[x][i]!=tree::jmp[y][i]){
				break;
			}
		}
		x=tree::jmp[x][i];
		y=tree::jmp[y][i];
	}
	return x;
}
namespace bing{
	int fa[100005];
	int to[100005];
	int getfa(int x){
		if(fa[x]==x){
			return x;
		}
		int temp=getfa(fa[x]);
		to[x]+=to[fa[x]];
		return fa[x]=temp;
	}
	void Union(int x,int y){//x under y
		int fax=getfa(x);
		int fay=getfa(y);
		fa[fax]=fay;
		to[fax]=to[y]+1;
		return ;
	}
	int query(int x,int y){
		int fax=getfa(x);
		int fay=getfa(y);
		if(fax!=fay){
			return -1;
		}
		int l=lca(x,y);
		getfa(l);
		return to[x]+to[y]-2*to[l];
	}
};
int uu[100005];
int vv[100005];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	#endif
	int n=read(),t;
	t=read();
	for(int i=1;i<=n;i++){
		tree::fir[i]=-1;
		bing::fa[i]=i;
	}
	for(int i=1;i<n;i++){
		int u=read(),v;
		v=read();
		tree::add(u,v);
		tree::add(v,u);
		uu[i]=u;
		vv[i]=v;
	}
	dfs(1,1);
	int r=0;
	for(int i=1;i<=t;i++){
		char temp[3];
		scanf("%s",temp+1);
		if(temp[1]=='C'){
			int e=read();
			int uuu=uu[e];
			int vvv=vv[e];
			if(tree::dep[uuu]>tree::dep[vvv]){
				std::swap(uuu,vvv);
			}
			bing::Union(vvv,uuu);
		}else if(temp[1]=='Q'){
			int a=read(),b;
			b=read();
			int temp=bing::query(a,b);
			if(temp==-1){
				r=r^(i+a+b);
			}else{
				r=(r+(i^temp))%998244353;
			}
		}
	}
	printf("%d",r);
	return 0;
}

