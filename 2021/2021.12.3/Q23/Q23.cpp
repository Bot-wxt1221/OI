#include <iostream>
#include <cstdio>
using namespace std;
int n,m,cnt=0;
void dfs(int step,int ans);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m;
	dfs(0,n);
	cout<<cnt;
	return 0;
}
void dfs(int step,int ans){
	if(ans==0){
		return;
	}
	if(step==m){
		cnt++;
		return;
	}
	dfs(step+1,ans+1);
	dfs(step+1,ans-1);
	return;
}
