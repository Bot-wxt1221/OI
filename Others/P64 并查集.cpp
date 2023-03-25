#include <iostream>
#include <cmath>
using namespace std;
const int MAXN=30000;
int fa[MAXN],dis[MAXN],sz[MAXN];
int find(int x); 
void Union(int x,int y);
int main(){
	int q;
	cin>>q;
	for(int i=0;i<30000;i++){
		fa[i]=i;
		sz[i]=1;
	}
	int x,y;
	char c;
	for(int i=0;i<q;i++){
		cin>>c;
		cin>>x>>y;
		if(c=='c'){
		if(find(x)==find(y)){
			cout<<abs(dis[x]-dis[y]-1)<<endl;
			continue;
		}
		cout<<"-1"<<endl;
	}
	else{
	Union(x,y);
		}
	}
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	int ff=find(fa[x]);
	dis[x]+=dis[fa[x]];
	return fa[x]=ff;
} 
void Union(int x,int y){
	int u,v;
	u=find(x);v=find(y);
	if(u==v){
		return;
	}
	fa[u]=v;dis[u]+=sz[v];
	sz[v]+=sz[u];
}
