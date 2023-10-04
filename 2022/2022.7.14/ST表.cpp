#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
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
int f[100005][10];
int main(){
	freopen("ST.in","r",stdin);
	freopen("2.out","w",stdout);
	srand(time(NULL));
	int n=read();
	for(int i=1;i<=n;i++){
		f[i][0]=read();
	}
	for(int j=1;j<=log2(n);j++){
		for(int i=1;i<=n;i++){//Be careful 
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	int m=read();
	for(int i=1;i<=m;i++){
		int a=read();
		int b=read();
		int lo=log2(b-a+1);
		printf("%d\n",max(f[a][lo],f[b-(1<<lo)+1][lo])); 
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



