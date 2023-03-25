#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[1005];
char b[1005];
char lef[1005];
char righ[1005];
int pos[1005];
int posa[1005];
char dfs(int ,int);
void out(int );
int main(){
	freopen("flist.in","r",stdin);
	freopen("flist.out","w",stdout);
	scanf("%s",a);
	scanf("%s",b);
	int siz=strlen(a);
	for(int i=0;i<siz;i++){
		pos[b[i]]=i;
		posa[a[i]]=i;
	}
	dfs(0,siz-1);
	out(b[0]);
	return 0;
}
char dfs(int l,int r){
	if(l>=r){
		return a[l];
	}
	int _min=10005;
	for(int i=l;i<=r;i++){
		_min=min(_min,pos[a[i]]);
	}
	if(posa[b[_min]]==l){
		lef[b[_min]]=dfs(posa[b[_min]]+1,r);
	}else if(posa[b[_min]]==r){
		righ[b[_min]]=dfs(l,posa[b[_min]]-1);
	}else{
		righ[b[_min]]=dfs(l,posa[b[_min]]-1);
		lef[b[_min]]=dfs(posa[b[_min]]+1,r);
	}
	return b[_min];
}
void out(int now){
	printf("%c",now);
	if(righ[now]!=0){
		out(righ[now]);
	}
	if(lef[now]!=0){
		out(lef[now]);
	}
	return ;
}
