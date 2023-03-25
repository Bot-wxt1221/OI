#include <iostream>
#include <cstdio>
#include <algorithm>
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
		int ax,by;
}x[100005],y[100005];

bool cmp(node a,node b){
	return a.ax<b.bx;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		x[i].ax=read();
		x[i].by=read();
	}
	for(int i=1;i<=n;i++){
		y[i].ax=read();
		y[i].by=read();
	}
	sort(x+1,x+n+1,cmp);
	sort(y+1,y+n+1,cmp);
	int j=1;
	for(int i=1;i<=n;i++){
		
	}
	cout<<ans;
	return 0;
}

