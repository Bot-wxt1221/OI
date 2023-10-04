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
int tree[2000005];
int n,q;
int lowbit(int a){
	return a&-a;
}
void add(int a,int b){
	while(a<=n){
		tree[a]+=b;
		a+=lowbit(a);
	}
	return ;
}
int query(int a){
	int ans=0;
	while(a>0){
		ans+=tree[a];
		a-=lowbit(a);
	}
	return ans;
}
signed main(){
	freopen("segment_tree1.in","r",stdin);
	freopen("segment_tree1.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		add(i,read());
	}
	for(int i=1;i<=q;i++){
		int op=read();
		if(op==1){
			int j=read();
			int x=read();
			add(j,x);
		}else{
			int l=read();
			int r=read();
			printf("%lld\n",query(r)-query(l-1));
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



