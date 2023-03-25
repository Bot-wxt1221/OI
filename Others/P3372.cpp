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
int a[400005];
int b[100005];
int mark[400005];
void dfs(int left,int right,int now);
void dfs2(int,int,int,int,int ,int);
int dfs3(int,int ,int ,int ,int );
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	dfs(1,n,1);
	for(int i=1;i<=m;i++){
		int a=read();
		if(a==1){
			int x=read(),y,k;
			y=read();
			k=read();
			dfs2(1,n,1,x,y,k);
		}else{
			int x=read(),y;
			y=read();
			printf("%lld\n",dfs3(1,n,1,x,y));
		}
	}
	return 0;
}
void dfs2(int left,int right,int now,int x,int y,int k){
	if(left>=right){
		return ;
	}
	if(mark[now]){
		a[now]+=mark[now]*(right-left+1);
		mark[now*2]+=mark[now];
		mark[now*2+1]+=mark[now];
		mark[now]=0;
	}
	if(x>right||y<left){
		return ;
	}else if(x<=left&&y>=right){
		mark[now]+=k;
		return ;
	}else{
		int mid=(right-left)/2+left;
		a[now]+=mark[now]*(right-left+1);
		mark[now*2]+=mark[now];
		mark[now*2+1]+=mark[now];
		mark[now]=0;
		dfs2(left,mid,now*2,x,y,k);
		dfs2(mid+1,right,now*2+1,x,y,k);
		a[now]+=a[now*2]+a[now*2+1];
	}

	return ;
}
void dfs(int left,int right,int now){
	if(left>=right){
		a[now]=b[left];
		return ;
	}
	int mid=(right-left)/2+left;
	dfs(left,mid,now*2);
	dfs(mid+1,right,now*2+1);
	a[now]+=b[now*2]+b[now*2+1];
	return ;
}
int dfs3(int left,int right,int now,int x,int y){
	if(left>right){
		return 0;
		}
	if(mark[now]){
		a[now]+=mark[now]*(right-left+1);
		mark[now*2]+=mark[now];
		mark[now*2+1]+=mark[now];
		mark[now]=0;
	}
	if(x>right||y<left){
		return 0;
	}else if(x<=left&&y>=right){
		return a[now];
	}else{
		int mid=(right-left)/2+left;
		int temp=dfs3(left,mid,now*2,x,y);
			temp+=dfs3(mid+1,right,now*2+1,x,y);
 			 return temp;
	}
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



