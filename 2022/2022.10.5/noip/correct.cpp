#include <iostream>
#include <cstdio>
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
int now;
int a[1005];
int nxt[1005];
int v[1005];
int fir[1005];
int in[1005];
priority_queue<int>can;
void add(int a,int b){
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int main(){
	freopen("correct.in","r",stdin);
	freopen("correct.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int u=read();
		int v=read();
		add(u,v);
		in[v]++;
	}
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			can.push(-i);
		}
	}
	while(can.size()>0){
		int temp=-can.top();
		printf("%d ",temp);
		can.pop();
		for(int i=fir[temp];i!=-1;i=nxt[i]){
			in[v[i]]--;
			if(in[v[i]]==0){
				can.push(-v[i]);
			}
		}
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



