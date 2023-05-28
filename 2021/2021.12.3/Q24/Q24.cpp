#include <iostream>
#include <cstdio>
using namespace std;
bool used[10];
int b[10][3]={{0,0,0},{0,1,2},{0,2,3},{0,1,4},{0,4,7},{0,7,8},{0,8,9},{0,9,6},{0,6,3}};
int a=0;
void dfs(int);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	dfs(9);
	cout<<a;
	return 0;
}
void dfs(int step){
	if(step<=0){
		a+=1;
		return;
	}
	for(int i=1;i<=9;i++){
		if(i==5){
			continue;
		}
		if(used[i]==1){
			continue;
		}
	
		used[i]=1;
		dfs(step-1);
		used[i]=0;
	}
	for(int i=1;i<=9;i++){
		if(used[b[i][1]]==1||used[b[i][2]]==1){
			continue;
		}
		used[b[i][1]]=used[b[i][2]]=1;
		dfs(step-2);
		used[b[i][1]]=used[b[i][2]]=0;
	}
	return;
}
