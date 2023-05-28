#include <iostream>
#include <cstdio>
using namespace std;
bool vised[10];
int vis[10];
int a[10][10];
int _ans[10];
int _max=0;
int n;
void dfs(int step);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dfs(0);
	for(int i=1;i<=n;i++){
		cout<<_ans[i]<<' ';
	}
	cout<<endl<<_max;
	return 0;
}
void dfs(int step){
	if(step==n){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][vis[i]]; 
		}
		if(ans>_max){
			for(int i=1;i<=n;i++){
				_ans[i]=vis[i];
			}
			_max=ans;
		} 
	}
	for(int i=1;i<=n;i++){
		if(vised[i])	continue;
		vised[i]=1;
		vis[step+1]=i;
		dfs(step+1);
		vised[i]=0;
	}
}
