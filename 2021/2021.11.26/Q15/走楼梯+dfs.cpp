#include <iostream>
#include <cstdio>
using namespace std;
int cnt=0;
void dfs(int a,int b,int c);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int a,b;
	cin>>a>>b;
	dfs(0,a,b);
	cout<<cnt;
	return 0;
}
void dfs(int a,int b,int c){
	if(a==b){
		cnt++;
		return;
	}
	if(a>10||b<=0){
		return;
	}
	for(int ai=1;ai<=4;ai++){
		for(int bi=1;bi<=4;bi++){
			dfs(a+ai,b-bi,c);
		}
	}
	return;
}
