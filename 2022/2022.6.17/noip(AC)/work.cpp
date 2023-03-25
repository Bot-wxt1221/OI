#include <iostream>
#include <cstdio>
#define int long long
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
bool vised[25];
int cost[25][25];
int _max;
int _mans[25];
int ans[25];
int n;
int to=0;
void dfs(int step);
signed main(){
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cost[i][j]=read();
		}
	}
	dfs(1);
	printf("%lld\n",_max);
	for(int i=1;i<=n;i++){
		printf("%lld:%lld\n",i,_mans[i]);
	}
	return 0;
}
void dfs(int step){
	if(step==n+1){
		if(to>_max){
			_max=to;
			for(int i=1;i<=n;i++){
				_mans[i]=ans[i];
			}
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vised[i]){
			continue;
		}
		vised[i]=1;
		ans[step]=i;
		to+=cost[step][i];
		dfs(step+1);
		vised[i]=0;
		ans[step]=0;
		to-=cost[step][i];
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


