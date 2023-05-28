#include <iostream>
#include <cstdio>
#include <cmath>
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
int go[100005][30]; 
int fir[10005];
int nxt[10005];
int dep[10005];
int v[10005];
void dfs(int ,int ); 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<n;i++){
		int a=read();
		int b=read();
		go[b][0]=a;
		nxt[i]=fir[a];
		fir[a]=i;
		v[i]=b;
	}
	for(int i=1;i<=log2(n);i++){
		for(int j=1;j<=n;j++){
			go[j][i]=go[go[j][i-1]][i-1];
		}
	}
	dfs(1,1);
	int a=read();
	int b=read();
	if(dep[a]>dep[b]){
		swap(a,b);
	}//de[a]<de[b]
	while(dep[a]!=dep[b]){
		int i=0;
		while(dep[go[b][i+1]]>dep[a]){
			i++;
		}
		b=go[b][i];
	}
	if(a==b){
		printf("%d",a);
		return 0;
	}
	int i=1;
	while(1){
		if(go[a][i]==go[b][i]){
			if(i==0){
				break;
			}
			a=go[a][i-1];
			b=go[b][i-1];
			i=0;
		}else{
			i++;
		}
	}
	printf("%d",a);
	return 0;
}
void dfs(int now,int de){
	dep[now]=de;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		dfs(v[i],de+1);
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



