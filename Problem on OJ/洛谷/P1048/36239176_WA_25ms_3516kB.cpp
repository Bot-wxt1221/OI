#include <iostream>
#include <algorithm>
using namespace std;
int _time[1000],s[1000],f[1000][1000];
int dfs(int n,int x);
int main(){
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>_time[i]>>s[i];
		f[i][i]=f[i-1][i-1]+s[i];
	}
	cout<<dfs(n,t);
}
int dfs(int n,int x){
	if(f[n][x]){
		return f[n][x];
	}
	return f[n][x]=max(f[n-1][x-_time[n]]+s[n],f[n-1][x]);
}
