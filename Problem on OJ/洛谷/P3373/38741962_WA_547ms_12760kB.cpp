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
int a[1000005],p;
int tree[4000005];
int length[4000005];
int lazy_1[4000005];
int lazy_2[4000005];
void push_down(int root){
	tree[root*2]=(tree[root*2]*lazy_2[root]+lazy_1[root]*(length[root*2]))%p;
	tree[root*2+1]=(tree[root*2+1]*lazy_2[root]+lazy_1[root]*(length[root*2+1]))%p;
	
	lazy_2[root*2]*=lazy_2[root];
	lazy_2[root*2]%=p;
	lazy_2[root*2+1]*=lazy_2[root];
	lazy_2[root*2+1]%=p;
	
	lazy_1[root*2]*=lazy_2[root];
	lazy_1[root*2]+=lazy_1[root];
	lazy_1[root*2]%=p;
	
	lazy_1[root*2+1]*=lazy_2[root];
	lazy_1[root*2+1]+=lazy_1[root];
	lazy_1[root*2+1]%=p;
	
	lazy_1[root]=0;
	lazy_2[root]=1;
	return ;
}
void build(int l,int r,int number){
	length[number]=r-l+1;
	lazy_2[number]=1;
	if(l==r){
		tree[number]=a[l];
		return;
	}
	if(l>r){
		return ;
	}
	lazy_2[number]=1;
	int mid=(l+r)/2;
	build(l,mid,number*2);
	build(mid+1,r,number*2+1);
	tree[number]=tree[number*2]+tree[number*2+1];
	tree[number]%=p;
	return ;
}
int ql,qr,ans,change;
void query(int l,int r,int number){
	push_down(number);
	if(l>r){
		return ;
	}
	int mid=(l+r)/2;
	if(ql<=l&&qr>=r){
		ans+=tree[number];
		ans%=p;
		return ;
	}
	if(qr<l){
		return ;
	}
	if(r<ql){
		return;
	}
	query(l,mid,number*2);
	query(mid+1,r,number*2+1);
	return ;
}
void plus_1(int l,int r,int number){
	push_down(number);
	if(l>r){
		return ;
	}
	int mid=(l+r)/2;
	if(ql<=l&&qr>=r){
		tree[number]*=change;
		tree[number]%=p;
		lazy_2[number]*=change;
		lazy_2[number]%=p;
		lazy_1[number]*=change;
		lazy_2[number]%=p;
		return ;
	}
	if(qr<l){
		return ;
	}
	if(r<ql){
		return;
	}
	push_down(number);
	plus_1(l,mid,number*2);
	plus_1(mid+1,r,number*2+1);
	tree[number]=tree[number*2]+tree[number*2+1];
	tree[number]%=p;
	return ;
}
void plus_2(int l,int r,int number){
	if(l>r){
		return ;
	}
	int mid=(l+r)/2;
	if(ql<=l&&qr>=r){
		tree[number]+=change*(length[number]);
		tree[number]%=p;
		lazy_1[number]+=change;
		lazy_1[number]%=p;
		return ;
	}
	if(qr<l){
		return ;
	}
	if(r<ql){
		return;
	}
	push_down(number);
	plus_2(l,mid,number*2);
	plus_2(mid+1,r,number*2+1);
	tree[number]=tree[number*2]+tree[number*2+1];
	tree[number]%=p;
	return ;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m;
	m=read();
	p=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		a[i]%=p;
	}
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int temp=read();
		switch(temp){
			case 1:{
				ql=read();
				qr=read();
				change=read();
				plus_1(1,n,1);
				break;
			}
			case 2:{
				ql=read();
				qr=read();
				change=read();
				plus_2(1,n,1);
				break;
			}
			case 3:{
				ql=read();
				qr=read();
				ans=0;
				query(1,n,1);
				printf("%d\n",ans); 
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


