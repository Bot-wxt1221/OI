#include <iostream>
#include <algorithm>
using namespace std;
int fa[1005];
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
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>road[i].x>>road[i].y>>road[i].t;
	}
	sort(road+1,road+1+n,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int fax=getfa(road[i].x);
		int fay=getfa(road[i].y);
		if(fax==fay){
			continue;
		}
		ans=max(ans,road[i].t);
		fa[fax]=fay;
	}
	int saans=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i){
			saans++;
		}
	}
	if(saans>1){
		cout<<-1;
		return 0;
	}
	cout<<ans;
	return 0;
}
