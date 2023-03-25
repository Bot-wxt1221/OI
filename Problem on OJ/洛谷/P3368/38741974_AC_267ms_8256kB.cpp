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
int lowbit(int temp){
	return temp&(-temp);
}
int n,m;
int yuan[500005];
int tree[500005];
void add(int x,int y){
	while(x<=n){
		tree[x]+=y;
		x+=lowbit(x);
	}
	return ;
}
int query(int x){
	int ans=0;
	while(x>0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		yuan[i]=read();
	}
	for(int i=1;i<=n;i++){
		tree[i]=yuan[i]-yuan[i-lowbit(i)];
	}
	query(3);
	for(int i=1;i<=m;i++){
		int temp=read();
		switch(temp){
			case 1:{
				int x=read(),y,k;
				y=read();
				k=read();
				add(x,k);
				add(y+1,-k);
				break;
			}
			case 2:{
				int x=read();
				printf("%lld\n",query(x));
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


