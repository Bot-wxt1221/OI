#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int zhi[10]={0,2,3,5,7,11,13};
int ans[10];
bool used[10];
int pai[10];
int a[3];
int use=0;
int _min=999999999;
void dfs(int step);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	dfs(1);
	cout<<_min;
	return 0;
}
void dfs(int step){
	if(use>2){
		return;
	}
	if(step==7){
		if(use!=2){
			return;
		}
		int n=0,m=0;
		for(int i=1;i<=6;i++){
			if(used[i]==0){
				pai[++n]=zhi[i];
			}else{
				a[++m]=zhi[i];
			}
		}
		while(next_permutation(pai+1,pai+1+n)){
			_min=min(_min,max(a[1]*a[1],max(a[1]*pai[1],max(pai[1]*pai[2],max(pai[2]*pai[3],max(pai[3]*pai[4],max(pai[4]*a[2],a[2]*a[2])))))));
		}
		return;
	}
	for(int i=0;i<=1;i++){
		use+=i;
		used[step]=i;
		dfs(step+1);
		used[step]=0;
		use-=i;
	}
}
