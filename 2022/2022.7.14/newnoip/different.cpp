#include <iostream>
#include <cstdio>
#include <deque>
#include <cmath>
#define mx(a,b) (((a)>(b)?(a):(b)))
#define mn(a,b) (((a)<(b))?(a):(b))
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
int a[200005];
int pos[200005];
int p[20000005];
int siz[200005];
int f[200005][30];
int binary(int l,int r){
	if(pos[l]==l){
		return l;
	}
	if(pos[r]<l){
		return r+1;
	}
	int mid,p=l;
	while(l<=r){
		mid=((l+r)>>1);
		if(pos[mid]>=p){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return l;
}
int ques(int l, int r) {
    int p = log2(r-l+1);
    return mx(f[l][p], f[r - (1 << p) + 1][p]);
}
int main(){
	freopen("different.in","r",stdin);
	freopen("different.out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		a[i]+=10000000;
//		cerr<<p[a[i]]<<endl;
		pos[i]=mx(pos[i-1],p[a[i]]+1);
		p[a[i]]=i;
		siz[i]=i-pos[i]+1;
		f[i][0]=siz[i];
	}
	for(int i=1;i<=log2(n);i++){
		for(int j=1;(j+(1<<(i)))-1<=n;j++){
			f[j][i]=mx(f[j][i-1],f[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<=m;i++){
		int a=read()+1;
		int b=read()+1;
		int ans=0;
		int t=binary(a,b);
		if(t>a){
			ans=t-a;
		}if(t<=b){
			ans=max(ans,ques(t,b));
		}
		printf("%d\n",ans);
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



