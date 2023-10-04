#include <iostream>
#include <cstdio>
#define MAXN 100000
using namespace std;
bool vised[MAXN];
int n,m,ans=0;
void dfs(int step,int a);
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	cin>>n>>m;
	if(n>m||(m-n)%2==1){
		cout<<0;
		return 0;
	}
	dfs(0,0);
	cout<<ans%10000007;
	return 0;
}
void dfs(int step,int a){
	if(step==m){
		if(a==n)
			ans++;
		return ;
	}
	dfs(step+1,a+1);
	dfs(step+1,a-1); 
	return ;
}
