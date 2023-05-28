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
int siz[100005];
int lazy[100005];
int a[100005];
int tree[400005];
void build(int now,int l,int r){
	if(l>r){
		return ;
	}
	siz[now]=r-l+1;
	if(l==r){
		tree[now]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	tree[now]=tree[now*2]+tree[now*2+1];
	return ;
}
inline void pushdown(int now){
	tree[now*2]+=lazy[now]*siz[now*2];
	tree[now*2+1]+=lazy[now]*siz[now*2+1];
	lazy[now*2]+=lazy[now];
	lazy[now*2+1]+=lazy[now];
	lazy[now]=0;
	return ;
}
int ql,qr,ans;
void ques(int now,int l,int r){
	if(l>r){
		return ;
	}
	pushdown(now);
	if(ql<=l&&r<=qr){
		ans+=tree[now];
		return ;
	}
	if(ql>r||qr<l){
		return ;
	}
	int mid=(l+r)/2;
	ques(now*2,l,mid);
	ques(now*2+1,mid+1,r);
	return ;
}
void add(int now,int l,int r){
	if(l>r){
		return ;
	}
	pushdown(now);
	if(ql<=l&&r<=qr){
		tree[now]+=ans*siz[now];
		lazy[now]+=ans;
		return ;
	}
	if(ql>r||qr<l){
		return ;
	}
	int mid=(l+r)/2;
	tree[now]+=ans*(min(r,qr)-max(l,ql)+1);
	add(now*2,l,mid);
	add(now*2+1,mid+1,r);
	return ;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int a=read();
		switch(a){
			case 1:{//add
				ql=read();
				qr=read();
				ans=read();
				add(1,1,n);
				break;
			}
			case 2:{
				ql=read();
				qr=read();
				ans=0;
				ques(1,1,n);
				printf("%lld\n",ans);
				break;
			}
				
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



