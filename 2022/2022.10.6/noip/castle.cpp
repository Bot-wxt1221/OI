#include <iostream>
#include <cstdio>
#include <queue>
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
int fir[1005*2];
int nxt[499505*2];
int v[499505*2];
int w[499505*2];
int now;
class node{
	public:
		int a,b;
};
bool operator < (node a,node b){
	return a.b>b.b;
}
priority_queue<node>a;
void add(int a,int b,int c){
	now++;
	v[now]=b;
	w[now]=c;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
bool vised[1005];
int to[1005];
int main(){
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int a=read();
		int b=read();
		int c=read();
		add(a,b,c);
		add(b,a,c);
	}
	memset(to,0x3f,sizeof(to));
	int inf=to[1];
//	vised[1]=1;
	to[1]=0;
	int sure=1;
	node abc;
	abc.a=1;
	abc.b=0;
	a.push(abc);
	while(a.size()>0&&sure<n){
		node temp=a.top();
		while(vised[temp.a]&&a.size()>0){
			a.pop();
			temp=a.top();
		}
		if(vised[temp.a]){
			break ;
		}
		vised[temp.a]=1;
		a.pop();
		sure++;
		for(int i=fir[temp.a];i!=-1;i=nxt[i]){
			if(to[v[i]]>temp.b+w[i]){
				to[v[i]]=temp.b+w[i];
				node abc;
				abc.a=v[i];
				abc.b=to[v[i]];
				a.push(abc);
			}
		}
	}
	long long ans=1;
	for(int i=2;i<=n;i++){
		if(to[i]==inf){
			printf("0");
			return 0;
		}
		int now=0;
		for(int j=fir[i];j!=-1;j=nxt[j]){
			if(to[v[j]]+w[j]==to[i]){
				now++;
			}
		}
		ans*=now;
		ans%=((1ll<<31ll)-1ll);
	}
	printf("%lld",ans);
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


