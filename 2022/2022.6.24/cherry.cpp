#include <iostream>
#include <cstdio>
#include <map>
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
int n,k;
int b[50];
int ans=0;
int now=0;
void dfs(int step);
signed main(){
	freopen("cherry.in","r",stdin);
	freopen("cherry.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
void dfs(int step){
	if(step==n+1){
		if(now==k){
			ans++;
		}
		return ;
	}
	dfs(step+1);
	now+=b[step];
	dfs(step+1);
	now-=b[step];
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


