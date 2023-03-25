#include <iostream>
#include <algorithm>
using namespace std;
int fa[10005];
class node{
	public:
		int x,y,t;
}road[100005];
int getfa(int n){
	return fa[n]==n?n:fa[n]=getfa(fa[n]);
}
bool cmp(node a,node b){
	return a.t<b.t;
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>road[i].x>>road[i].y>>road[i].t;
	}
	sort(road+1,road+1+m,cmp);
	int ans=0;
	int use=1;
	for(int i=1;i<=m&&use<k;i++){
		int fax=getfa(road[i].x);
		int fay=getfa(road[i].y);
		if(fax==fay){
			continue;
		}
		use++;
		ans+=road[i].t;
		fa[fax]=fay;
	}
	if(use<k){
		cout<<"No Answer";
		return 0;
	}
	cout<<ans;
	return 0;
}
