#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
inline int read();
class node{
	public:
		int now,i;
		node(int ii=0,int nn=0){
			i=ii;
			now=nn;
		}
}block[1000005];
bool operator < (node a,node b){
	return a.now<b.now;
}
bool operator == (node a,node b){
	return a.now==b.now;
}
int arr[1000005];
int lazy[1005];
int yuan[1005];
int inarr[1000005];
int ll[1005];
int rr[1005];
void reset(int now){
	for(int i=ll[now];i<=rr[now];i++){
		block[i].now=arr[i];
		block[i].i=i;
	}
	std::sort(block+ll[now],block+rr[now]+1);
	return ;
}
void add(int l,int r,int w){
	if(yuan[l]==yuan[r]){
		for(int i=1;i<=r;i++){
			arr[i]+=w;
		}
		return ;
	}
	for(int i=l;i<=rr[yuan[l]];i++){
		arr[i]+=w;
	}
	for(int i=ll[yuan[r]];i<=r;i++){
		arr[i]+=w;
	}
	for(int i=yuan[l]+1;i<yuan[r];i++){
		lazy[i]+=w;
	}
	reset(yuan[l]);
	reset(yuan[r]);
	return ;
}
int que(int l,int r,int w){
	int ans=0;
	if(yuan[l]==yuan[r]){
		for(int i=1;i<=r;i++){
			if(lazy[yuan[l]]+arr[i]>=w){
				ans++;
			}
		}
		return ans;
	}
	for(int i=l;i<=rr[yuan[l]];i++){
		if(lazy[yuan[l]]+arr[i]>=w){
			ans++;
		}
	}
	for(int i=ll[yuan[r]];i<=r;i++){
		if(lazy[yuan[r]]+arr[i]>=w){
			ans++;
		}
	}
	for(int i=yuan[l]+1;i<yuan[r];i++){
		int find=std::lower_bound(block+ll[i],block+rr[i]+1,node(0,w-lazy[i]))-block;
		if(find!=rr[i]+1){
			ans+=rr[i]-find+1;
		}
	}
	return ans;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read();
	int q=read();
	for(int i=1;i<=n;i++){
		arr[i]=read();
	}
	int now=1;
	int blocksize=sqrt(n);
	ll[now]=1;
	for(int i=1;i<=n;i++){
		if(i-ll[now]+1>blocksize){
			std::sort(block+ll[now],block+rr[now]+1);
			now++;
			ll[now]=i;
		}
		yuan[i]=now;
		block[i].i=i;
		block[i].now=arr[i];
		rr[now]=i;
	}
	for(int i=1;i<=q;i++){
		char a[20];
		int l,r,w;
		scanf("%s%d%d%d",&a,&l,&r,&w);
		if(a[0]=='M'){
			add(l,r,w);
		}else{
			printf("%d\n",que(l,r,w));
		}
	}
	return 0;
}
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

