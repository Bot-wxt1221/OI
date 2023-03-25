#include <iostream>
#include <queue>
#include <cstdio>
// #define int long long
using namespace std;
inline int read();
int s[100005];
int w[100005];
int fir[100005];
int in[100006];
int nxt[100005];
queue<int>a;
int v[100006];
int now;
inline void add(int x,int y,int z){
	now++;
	v[now]=y;
	w[now]=z;
	in[y]++;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
inline void Write(int x)
{
	register int c=0,s[15]; do s[++c]=x%10; while(x/=10);
	while(c) putchar(s[c--]+'0'); putchar('\n');
}
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    register int n=read(),m,c;
	m=read();
	c=read();
	for(register int i=1;i<=n;i++){
		s[i]=read();
		fir[i]=-1;
	}
	for(register int i=1;i<=c;i++){
		register int a=read();
		register int b=read();
		register int x=read();
		add(a,b,x);
	}
	for(register int i=1;i<=n;i++){
		if(in[i]==0){
			a.push(i);
		}
	}
	while(a.size()>0){
		register int temp=a.front();
		a.pop();
		for(int i=fir[temp];i!=-1;i=nxt[i]){
			s[v[i]]=max(s[v[i]],s[temp]+w[i]);
			in[v[i]]--;
			if(in[v[i]]==0){
				a.push(v[i]);
			}
		}
	}
	for(register int i=1;i<=n;i++){
		Write(s[i]);
	}
	return 0;
}
inline int read(){
	register int x=0,f=1;char c=getchar();
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
