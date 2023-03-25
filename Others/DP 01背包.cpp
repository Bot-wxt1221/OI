#include <iostream>
#include <algorithm>
using namespace std;
int stime[1000],s[1000],f[1000][1000];
int dfs(int n,int x);
int main(){
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>stime[i]>>s[i];
		f[i][i]=f[i-1][i-1]+s[i];
	}
	cout<<dfs(n,t);
}
int dfs(int n,int x){//n为几个药   x为时间 
	if(f[n][x]){
		return f[n][x];
	}
	return f[n][x]=max(f[n-1][x-stime[n]]+s[n],f[n-1][x]);
}
