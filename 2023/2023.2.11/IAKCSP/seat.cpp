#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
deque<int>a;
bool used[15][15];
bool vised[15];
int ans[15];
int now=0;
int n;
void dfs(int ,int );
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		int m=read();
		for(int j=1;j<=m;j++){
			int a=read();
			used[i][a]=1;
			used[a][i]=1; 
		}
	}
	vised[1]=1;
	ans[1]=1;
	dfs(2,1);
	printf("%d",now);
	return 0;
}
void dfs(int step,int last){
	if(step==n+1){
		for(int i=2;i<n;i++){
			if(used[ans[i]][ans[i-1]]==0||used[ans[i]][ans[i+1]]==0){
				return ;
			}
		}
		if(used[ans[1]][ans[2]]==0){
			return ;
		}
		if(used[ans[n]][ans[n-1]]==0){
			return ;
		}
		if(used[ans[1]][ans[n]]==0||used[ans[n]][ans[1]]==0){
			return ;
		}
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
		now++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vised[i]){
			vised[i]=1;
			ans[step]=i;
			dfs(step+1,i);
			vised[i]=0;
			ans[step]=0;
		}
	}
	return ;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


