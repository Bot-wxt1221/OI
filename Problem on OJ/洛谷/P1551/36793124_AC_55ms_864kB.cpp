#include <iostream>
using namespace std;
const int MAXN=10000;
int fa[MAXN];
int siz[MAXN];
int find(int x); 
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		fa[i]=i;
		siz[i]=0;
	}
	int x,y;
	for(int i=0;i<m;i++){
		int n,m; 
		cin>>x>>y;
		n=find(x);
		m=find(y);
		if(siz[m]<siz[n]){
			swap(n,m);
		}
		//siz[m]>siz[n]
		fa[n]=m;
		siz[m]=max(siz[m],siz[n]+1);
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		if(find(x)==find(y)){
			cout<<"Yes"<<endl;
			continue;
		}
		cout<<"No"<<endl;
	}
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
