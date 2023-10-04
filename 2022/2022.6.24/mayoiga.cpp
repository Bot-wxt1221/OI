#include <iostream>
#include <cstdio>
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
int to[2000005];
int first[1000005];
int v[2000005];
int head=0;
int tail=0;
int queue[2000005];
int length[2000005];
bool vised[2000005];
int main(){
	freopen("mayoiga.in","r",stdin);
	freopen("mayoiga.out","w",stdout);
	int n=read(),m,k,d;
	m=read();
	k=read();
	d=read();
	for(int i=0;i<n;i++){
		first[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int temp=read();
		v[i]=read();
		to[i]=first[temp];
		first[temp]=i;
		v[i+m]=temp;
		to[i+m]=first[v[i]];
		first[v[i]]=i+m;
	}
	queue[tail++]=k;
	vised[k]=1;
	int ans=100000000,total=0;
	while(head!=tail){
		for(int i=first[queue[head]];i!=-1&&length[head]<ans;i=to[i]){
			if(vised[v[i]])	continue;
			vised[v[i]]=1;
			queue[tail++]=v[i];
			length[tail-1]=length[head]+1;
			if(v[i]==d){
				ans=length[tail-1];
				total++;
				vised[v[i]]=0;
				if(total>998244853){
					total=1;
				}
			}
		}
		vised[queue[head]]=0;
		head++;
	}
	printf("%d",total%998244853);
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


