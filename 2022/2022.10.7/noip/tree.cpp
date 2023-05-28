#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	char a=getchar();
	int f=1,x=0;
	while('0'>a||a>'9'){
		(a=='-')?f=-1:0;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=(x<<3)+(x<<1)+(a-'0');
		a=getchar();
	}
	return f*x;
}
int ans;
int v[1000005];
int l[1000005];
int r[1000005];
int son[1000005];
int siz[1000005];
bool dfs(int nl,int nr){
	if(nl==nr&&nl==-1){
		return 1;
	}
	if(nl==-1){
		return 0;
	}
	if(nr==-1){
		return 0;
	}
	return v[nl]==v[nr]&&dfs(r[nl],l[nr])&&dfs(l[nl],r[nr]);
}
void dfs2(int now){
	siz[now]=1;
	if(l[now]!=-1){
		dfs2(l[now]);
		siz[now]+=siz[l[now]];
	}
	if(r[now]!=-1){
		dfs2(r[now]);
		siz[now]+=siz[r[now]];
	}
	if(dfs(l[now],r[now])){
		ans=max(ans,siz[now]);
	}
	return ;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		v[i]=read();
	}
	for(int i=1;i<=n;i++){
		l[i]=read();
		r[i]=read();
		if(l[i]!=-1){
			son[l[i]]=1;
		}
		if(r[i]!=-1){
			son[r[i]]=1;
		}
//		son[l[i]]=son[r[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(son[i]==0){
			dfs2(i);
			dfs(l[i],r[i]);
			break;
		}
	}
	printf("%d",ans);
	return 0;
}

