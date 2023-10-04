#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
class node{
	int a,b,t,u,v,w,x;
};
vector <node > a;
bool cmp(node a,node b){
	return a.t==b.t?a.v>b.v:a.t<b.t;
}
queue<node>wait;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int f,m,n,l;
	while(cin>>f&&f!=0){
		cin>>m>>n>>l;
		for(int i=1;i<=l;i++){
			node b;
			cin>>b.a>>b.b>>b.t>>b.u>>b.v>>b.w>>b.x;
			a.push_back(b);
		}
		for(int i=1;i<=f;i++){
			sort(a.begin(),a.end(),cmp);
			int morem=m,moren=n;
			
		}
	}
	return 0;
}

