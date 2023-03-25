#include <iostream>
#include <cstdio>
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
int ans=0;
int n;
void dfs(int);
int stack[105];
int top=0;
int main(){
	freopen("tile.in","r",stdin);
	freopen("tile.out","w",stdout);
	n=read();
	dfs(0);
	printf("%d",ans);
	return 0;
}
void dfs(int now){
	if(now>n){
		return ;
	}
	if(now==n){
		printf("%d=%d",n,stack[0]);
		for(int i=1;i<top;i++){
			printf("+%d",stack[i]);
		}
		printf("\n");
		ans++;
		return ;
	}
	if(stack[top-1]==1){
		for(int i=2;i<=3;i++){
			stack[top++]=i;
			dfs(now+i);
			top--;
		}
	}else{
		for(int i=1;i<=3;i++){
			stack[top++]=i;
			dfs(now+i);
			top--;
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


