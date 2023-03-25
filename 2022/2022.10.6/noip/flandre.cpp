#include <iostream>
#include <cstdio>
#include <set>
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
int n;
int tree[4000005];
//int al[4000005];
void build(int now,int l,int r){
	if(l==r){
		tree[now]=1;
//		al[now]=l;
		return ;
	}
	tree[now]=r-l+1;
	int mid=(l+r)/2;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	return ;
}
int que;
int find(int now,int l,int r,int number){
	if(l==r){
		int a=now;
		while(now>0){
			tree[now]--;
			now=now/2;
		}
		return l;
	}
	int mid=(l+r)/2;
	if(number+tree[now*2]-1>=que){
		return find(now*2,l,mid,number);
	}else{
		return find(now*2+1,mid+1,r,number+tree[now*2]);
	}
}
int b[1000005];
int main(){
	freopen("flandre.in","r",stdin);
	freopen("flandre.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	build(1,1,n);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		que=read();
		int temp=find(1,1,n,1);
		printf("%d\n",b[temp]);
		
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



