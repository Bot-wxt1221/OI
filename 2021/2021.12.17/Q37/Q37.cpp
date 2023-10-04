#include <iostream>
#include <cstdio>
using namespace std;
bool vised[10];
int vis[10];
int bit[10]={0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x7B};
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
	if(step==10){
		int ans=0;
		for(int i=1;i<=9;i++){
			unsigned int a=vis[i-1]^vis[i];
			while(a!=0){
				if(a&1==1){
					ans++;
				}
				a=a/2;
			}

		}
		_min=min(_min,ans);
		return;
	}
	for(int i=1;i<=9;i++){
		if(vised[i])	continue;
		vised[i]=1;
		vis[step]=i;
		dfs(step+1);
		vised[i]=0;
	}
	return;
}
