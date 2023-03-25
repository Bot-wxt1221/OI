#include <iostream>
#include <cstdio>
#define int long long 
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

class node{
	public:
		node *l;node *r;
		node(){
			l=r=NULL;
		}
		int data;
}a[5000005];
void dfs(node *);
void dfs2(node *);
void insert(int m,node *);
int now=0;
signed main(){
	freopen("insert_bst.in","r",stdin);
	freopen("insert_bst.out","w",stdout);
	int m=read();
	for(int i=1;i<=m;i++){
		char aa[30];
		scanf("%s",aa);
		if(aa[0]=='i'){
			int n=read();
			if(now==0){
				now++;
				a[now].data=n;
			}else{
				insert(n,&a[1]);
			}
		}else{
			dfs2(&a[1]);
			printf("\n");
			dfs(&a[1]);
			printf("\n");
		}
	}
	return 0;
}
void insert(int m,node *b){
	if(b->data >m &&b->l!=NULL){
		insert(m,b->l);
	}else if(b->data < m &&b->r!=NULL){
		insert(m,b->r);
	}else if(b->data >m){
		now++;
		a[now].data=m;
		b->l=&a[now];
	}else{
		now++;
		a[now].data=m;
		b->r=&a[now];
	}
	return ;
}
void dfs(node *a){
	printf("%lld ",a->data);
	if(a->l!=NULL){
		dfs(a->l);
	}
	if(a->r!=NULL){
		dfs(a->r);
	}
	return ;
}
void dfs2(node *a){
	if(a->l!=NULL){
		dfs2(a->l);
	}
	printf("%d ",a->data);
	if(a->r!=NULL){
		dfs2(a->r);
	}
	return ;
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



