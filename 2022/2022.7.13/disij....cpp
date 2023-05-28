#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
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
int w[1000005];
int v[1000005];
int nex[1000005];
int first[1000005];
long long dis[1000005];
bool vised[1000005];
class node{
	public:
		int a,dis;
};
bool operator < (node a,node b){
	return a.dis>b.dis;
}
priority_queue<node>cho;
int main(){
//	freopen("5.in","r",stdin);
//	freopen("5.out","w",stdout);
	int n=read(),m,k;
	m=read();
	k=read();
	for(int i=1;i<=n;i++){
		first[i]=-1;
		dis[i]=(1ll<<60);
	}
	for(int i=1;i<=m;i++){
		int a=read(),b,c;
		b=read();
		c=read();
		if(a==k){
			dis[b]=c;
			cho.push(node({b,c}));
		}
		v[i]=b;
		w[i]=c;
		nex[i]=first[a];
		first[a]=i;
	}
	dis[k]=0;
//	int ok=1;
	while(cho.size()>0){
		int chos=cho.top().a;
		while(vised[chos]==1&&cho.size()>0){
			cho.pop();
			chos=cho.top().a;
		}if(cho.size()==0)break;
		vised[chos]=1;
		cho.pop();
		for(int i=first[chos];i!=-1;i=nex[i]){
			if(!vised[v[i]]){
				dis[v[i]]=min(dis[v[i]],dis[chos]+w[i]);
				if(dis[chos]+w[i]==dis[v[i]])
					cho.push(node{v[i],dis[v[i]]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[i]==(1ll<<60)){
			printf("INF ");
		}else
			printf("%d ",dis[i]);
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


