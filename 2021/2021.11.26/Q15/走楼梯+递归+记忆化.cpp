#include <iostream>
#include <cstdio>
#define MAXN 10000
using namespace std;
unsigned long long d[MAXN][MAXN];
unsigned long long dfs(int a,int b,int c);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int a,b;
	cin>>a>>b;
	cout<<dfs(0,a,b)<<endl;
	return 0;
}
unsigned long long dfs(int a,int b,int c){
	if(d[a][b]!=0){
		return d[a][b];
	}
	if(a==b){
		return d[a][b]=1;
	}
	if(a>b){
		return 0;
	}
	int cnt=0;
	for(int ai=1;ai<=c;ai++){
		for(int bi=1;bi<=c;bi++){
			cnt+=dfs(a+ai,b-bi,c);
		}
	}
	return d[a][b]=cnt;
}
