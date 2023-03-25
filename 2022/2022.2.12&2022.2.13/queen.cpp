#include <iostream>
#include <cstdio>
using namespace std;
int n;
bool have=0;
bool vis[15];
bool cx[15];
int ans[15];
void dfs(int step);
int main(){
	freopen("queen.in","r",stdin);
	freopen("queen.out","w",stdout);
	cin>>n;
	dfs(1);
	if(!have){
		cout<<"no solute!";
	}
	return 0;
}
void dfs(int x){
	if(x==n+1){
		have++;
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
		return ;
	}
	for(int y=1;y<=n;y++){
		if(vis[x+y])	continue;
		if(vis[x-y+10])	continue;
		if(cx[y])		continue;
		ans[x]=y;
		vis[x+y]=1;
		vis[x-y+10]=1;
		cx[y]=1;
		dfs(x+1);
		vis[x+y]=0;
		vis[x-y+10]=0;
		cx[y]=0;
	}
}
