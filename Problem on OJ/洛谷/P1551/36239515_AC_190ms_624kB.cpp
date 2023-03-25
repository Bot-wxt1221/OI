#include <iostream>
using namespace std;
const int MAXN=10000;
int fa[MAXN];
int find(int x); 
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		fa[i]=i;
	}
	int x,y;
	for(int i=0;i<m;i++){
		int n,m; 
		cin>>x>>y;
		n=find(x);
		m=find(y);
		fa[n]=m;
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
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
} 