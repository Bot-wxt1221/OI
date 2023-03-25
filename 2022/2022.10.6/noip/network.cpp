#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
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
class node{
	public:
		int u,v,w;
};
class node2{
	public:
		int u,v,w;
};
bool operator<(node a,node b){
	return a.w>b.w;
}
bool operator<(node2 a,node2 b){
	return a.w>b.w;
}
priority_queue<node>a;
node2 b[505*505];
int dis(int x1,int y1,int x2,int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int x[505],y[505];
int dis2[505][505];
int fa[505];
bool have[505];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
signed main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	int n=read(),k;
	k=read();
	int same=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		x[i]=read();
		y[i]=read();
		int now=0;
		for(int j=1;j<i;j++){
			
			if(x[i]==x[j]&&y[i]==y[j]){
				now++;
			}
			node temp;
			temp.u=i;
			temp.v=j;
			temp.w=dis(x[i],y[i],x[j],y[j]);
			a.push(temp);
		}
		same=max(same,now);
	}
	int go=0;
	if(same==n){
		printf("0");
		return 0;
	}
	while(go<n-1-same&&a.size()>0){
		node temp=a.top();
		a.pop();
		if(getfa(temp.u)==getfa(temp.v)){
			continue;
		}
		go++;
		fa[getfa(temp.u)]=fa[getfa(temp.v)];
		node2 temp2;
		temp2.u=temp.u;
		temp2.v=temp.v;
		temp2.w=temp.w;
		b[go]=temp2;
	}
	sort(b+1,b+go+1);
	printf("%.2lf",sqrt(b[k].w));
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



