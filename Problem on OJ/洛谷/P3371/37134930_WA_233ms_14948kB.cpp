#include <iostream>
#include <cstdio>
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
int first[100005];
int nex[1000005];
int v[1000005];
int w[1000005];
bool vised[1000005];
int vised2[1000005];
long long dis[1000005];
queue<int>a;
int main(){
// 	freopen("h.in","r",stdin);
// 	freopen("4.out","w",stdout);
	int n=read(),m,k;
	m=read();
	k=read();
	for(int i=1;i<=n;i++){
		first[i]=-1;
		dis[i]=(1ll<<60);
	}
	for(int i=1;i<=m;i++){
		int u=read();
		v[i]=read();
		w[i]=read();
		nex[i]=first[u];
		first[u]=i;
	}
	dis[k]=0;
	a.push(k);
	while(a.size()>0){
		int now=a.front();
		a.pop();
		vised[now]=0;
		for(int i=first[now];i!=-1;i=nex[i]){
			if(dis[v[i]]>dis[now]+w[i]){
				dis[v[i]]=dis[now]+w[i];
				if(vised[v[i]]==0){
					vised[v[i]]=1;
					vised2[v[i]]++;
					if(vised2[v[i]]>=n){
						printf("No answer!");//负权回路
						return 0; 
					}
					a.push(v[i]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[i]==(1ll<<60)){
			printf("INF ");
		}else{
			printf("%d ",dis[i]);
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


