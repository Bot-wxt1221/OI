#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
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
int now=0;
bitset<1005> p[1005];
void add(int x,int y){
	p[x][y]=1;
	return ;
}
int n,m;
int ans=0;
bool go[1005];
void dfs(int i,int way);
int main(){
	freopen("rank.in","r",stdin);
	freopen("rank.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		p[i][i]=1;
	}
	for(int i=1;i<=m;i++){
		int a=read();
		add(a,read());
	}
	int ans=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(p[i][k])	p[i]=p[i]|p[k];	
		}
	}
	for(int i=1;i<=n;i++){
		ans+=p[i].count();
	}
	cout<<((n)*(n+1)/2)-ans;
	return 0;
}
/*
Anything about this program:
Type:
	Example
Description:
	已知一些数的大小关系求最少再需要多少对关系才能确定所有的大小关系 
Example:
	1:
		In:
			5 5
			2 1
			1 5
			2 3
			1 4
			3 4
		Out:
			3
More:
	Bitset 
*/


