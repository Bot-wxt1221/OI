#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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
class gra{
	public:
		int map[505][505];
		int now;
		gra(int n=500);
		inline void add(int,int);
}a;
gra::gra(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			map[i][j]=0;
		}
	}
	return ;
}
inline void gra::add(int x,int y){
	map[x][y]++;
	map[y][x]++;
	return ;
}
bool ans=0;
int ansa[2005];
int use=0;
int du[505];
bool have[505];
int _max=0;
int f;
void dfs(int now,int step);
int main(){
	freopen("fence7.in","r",stdin);
	freopen("fence.out","w",stdout);
	f=read();
	for(int i=1;i<=f;i++){
		int j,m;
		j=read();m=read();
		a.add(j,m);
		du[j]++;
		du[m]++;
		_max=max(_max,max(j,m));
	}
	for(int i=1;i<=_max;i++){
		if(du[i]%2==1){
			ansa[1]=i;
			dfs(i,2);
			return 0;
		}
	}
	ansa[1]=1;
	dfs(1,2);
	return 0;
}
void dfs(int now,int step){
	if(ans)	return ;
	if(step==f+2){
		for(int i=1;i<step;i++){
			printf("%d\n",ansa[i]);
		}
		ans=1;
		return ;
	}
	for(int i=1;i<=_max;i++){
		if(a.map[now][i]>0){
			a.map[now][i]--;
			a.map[i][now]--;
			ansa[step]=i;
			dfs(i,step+1);
			a.map[now][i]++;
			a.map[i][now]++;
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


