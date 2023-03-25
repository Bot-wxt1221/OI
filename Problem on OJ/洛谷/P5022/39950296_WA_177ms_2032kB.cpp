#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
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
int del=0;
int x[50005],y[50005];
vector<int>map[50005];
bool finish=0;
int no;
int ans2[50005];
int ans[50005];
bool vised[50005];
void dfs(int now,int fa){
	if(finish){
		return ;
	}
	if(x[del]==now&&y[del]==fa){
		return ;
	}
	if(y[del]==now&&x[del]==fa){
		return ;
	}
	if(vised[now]==1){
		finish=1;
		return ;
	}
	vised[now]=1;
	ans2[++no]=now;
	for(int i=0;i<map[now].size();i++){
		if(map[now][i]==fa){
			continue;
		}
		dfs(map[now][i],now);
	}
	return ;
}
int main(){
// 	freopen("travel.in","r",stdin);
// 	freopen("travel.out","w",stdout);
	int n=read();
	int m=read();
	for(int i=1;i<=m;i++){
		int a=read();
		int b=read();
		x[i]=a;
		y[i]=b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		sort(map[i].begin(),map[i].end());
	}
	if(m==n-1){
		dfs(1,0);
		for(int i=1;i<=n;i++){
			printf("%d ",ans2[i]);
		}
	}else{
		bool have=0;
		for(int i=1;i<=m;i++){
			no=0;
			del=i;
			dfs(1,0);
			if(have){
				bool big=1;
				for(int i=1;i<=n;i++){
					vised[i]=0;
					if(ans2[i]>ans[i]){
						big=0;
						break;
					}else if(ans2[i]<ans[i]){
						big=1;
						break;
					}
				}
				if(big){
					for(int i=1;i<=n;i++){
						ans[i]=ans2[i];
					}
				}
			}else if(no==n){
				have=1;
				for(int i=1;i<=n;i++){
					vised[i]=0;
					ans[i]=ans2[i];
				}
			}else{
				for(int i=1;i<=n;i++){
					vised[i]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		//删边 
	}
	return 0;
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


