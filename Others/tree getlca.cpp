#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define MAXN 1000
vector<int>Q[MAXN];
int de[MAXN];
int fath[MAXN];
void link(int fa,int so);
void dfs(int n,int de);
int getlca(int x,int y);
int main() {
//	freopen("tree.in","r",stdin);
	int n,fa,so;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>fa>>so;
		link(fa,so);
	}
	dfs(0,0);
	int x,y;
	cin>>x>>y;
	cout<<getlca(x,y);
	return 0;
}
void link(int fa,int so){
	Q[fa].push_back(so);
	fath[so]=fa;
}
void dfs(int n,int det){
	de[n]=det;
	for(int i=0;i<Q[n].size();i++){
		dfs(Q[n][i],det+1);
	}
}
int getlca(int x,int y){
	while(x!=y){
		if(de[x]>=de[y]){
			x=fath[x];
		}
		else{
		y=fath[y]; 
		}
	return x;
	}
}
