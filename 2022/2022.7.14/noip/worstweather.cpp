#include <iostream>
#include <cmath>
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
int f[50005][100];
int to[50005];
int n;
int find(int x){
	for(int i=1;i<=n;i++){
		if(to[i]==x){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("worstweather.in","r",stdin);
	freopen("worstweather.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		int y=read();
		int r=read();
		f[i][0]=r;
		to[i]=y;
	}
	for(int k=1;k<=log2(n);k++){
		for(int i=1;i<=n;i++){
			f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
		}
	}
	int m=read();
	for(int i=1;i<=m;i++){
		bool nex=1;
		int y=read(),x=read();
		y++;
		int lg=log2(find(x)-find(y)+1);
		int fx=find(x);
		int _max=max(f[find(y)][lg],f[fx-(1<<lg)+1][lg]);
		if(_max!=f[fx][0]){
			printf("false\n");
			continue;
		}
		int mi=min(y,x);
		int mx=max(x,y);
		for(int i=mi;i<=mx;i++){
			if(find(i)==0){
				printf("maybe\n");
				nex=0;
				break;
			}
		}
		if(nex){
			printf("true\n");
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



