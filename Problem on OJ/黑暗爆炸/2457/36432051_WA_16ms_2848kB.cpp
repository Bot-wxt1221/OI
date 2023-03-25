#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
int read(){
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
		int data,i;
}a[200005];
int maxx[200005];
int minx[200005]; 
bool cmp(node a,node b){
	return a.data==b.data?a.i<b.i:a.data<b.data;
}
int main(){
//	freopen("deque.in","r",stdin);
//	freopen("deque.out","w",stdout);
	int n=read(),cnt=0;
	for(int i=1;i<=n;i++){
		a[i].data=read();
		a[i].i=i;
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i==1||a[i].data!=a[i-1].data){
			maxx[++cnt]=a[i-1].i;
			minx[cnt]=a[i].i;
		}
	}
	maxx[++cnt]=a[n].i;
	bool b=1;
	int h=0x3f3f3f3f;
	for(int i=2;i<=cnt;i++){
		if(!b){
			if(h>maxx[i])	h=minx[i];
			else	h=maxx[i],b=1;
		} else{
			if(h<minx[i])	h=maxx[i];
			else	h=minx[i],b=0,ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:
			6 3 6 0 9 6 3
		Out:
			2
More:

*/
