#include <iostream>
#include <cstdio>
#include <stack>
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
int fir[100005];
int nxt[100005];
int v[100005];
bool go[100005];
int in[100005];
stack<int>no_in;
void add(int a,int b){
	in[b]++;
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<=n;i++){
		int temp=read();
		while(temp!=0){
			add(i,temp);
			temp=read();
		}
	}
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			no_in.push(i);
			go[i]=1;
		}
	}
	int have=0;
	while(have<n){
		have++;
		int temp=no_in.top(); 
		no_in.pop();
		printf("%d ",temp);
		for(int i=fir[temp];i!=-1;i=nxt[i]){
			in[v[i]]--;
			if(in[v[i]]==0&&go[v[i]]==0){
				no_in.push(v[i]);
				go[v[i]]=1;
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


