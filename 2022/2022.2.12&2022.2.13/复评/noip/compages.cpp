/*
大水题，直接dfs 
*/#include <iostream>
#include <cstdio>
using namespace std;
int n,r;
int vis[100];
void dfs(int step,int last);
int main(){
	freopen("compages.in","r",stdin);
	freopen("compages.out","w",stdout);
	cin>>n>>r;
	dfs(0,0);
	return 0;
}
void dfs(int step,int last){
	if(step==r){
		for(int i=0;i<r;i++){
			cout<<vis[i]<<' ';
		}
		cout<<endl;
		return ;
	}
	for(int i=last+1;i<=n;i++){
		vis[step]=i;
		dfs(step+1,i);
	}
}


