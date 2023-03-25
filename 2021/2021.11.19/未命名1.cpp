#include <iostream>
#include <cstdio>
using namespace std;
int cnt=0;
const int coin[5]={0,500,100,50,10};
void dfs(int step,int v,int n);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	dfs(1,1000,15);
	cout<<cnt;
	return 0;
}
void dfs(int step,int v,int n){
	if(step==4){
		if(v==0&&n>=0){
			cnt++;
		}
		return;
	}
	for(int i=0;i<=v/coin[step];i++){
		if(v-i*coin[step]>=0&&n-i>=0){
			dfs(step+1,v-i*coin[step],n-i);
		}
	}
}
