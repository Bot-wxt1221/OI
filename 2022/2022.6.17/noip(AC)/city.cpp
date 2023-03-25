#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
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
queue<int>bfs;
vector<int>a[105];
bool vised[105];
int view[105];
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	int n=read();
	int m=read();
	for(int i=1;i<=m;i++){
		int x=read();
		int y=read();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	bfs.push(1);
	vised[1]=1;
	view[1]=0;
	while(bfs.size()>0){
		int top=bfs.front();
		for(int i=0;i<a[top].size();i++){
			if(a[top][i]==n){
				printf("%d",view[top]);
				return 0;
			}
			if(vised[a[top][i]]){
				continue;
			}
			view[a[top][i]]=view[top]+1;
			vised[a[top][i]]=1;
			bfs.push(a[top][i]);
		}
		vised[top]=0;
		bfs.pop();
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


