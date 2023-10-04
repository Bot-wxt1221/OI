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
int n,m;
int d[1005][1005];
char map[1005][1005];
int ans=0;
int stack[1005];
int w[1005];
int top=0;
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%c",&map[i][j]);
			getchar();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]!='R'){
				d[i][j]=d[i-1][j]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		top=0;
		int a;
		d[i][m+1]=0;
		for(int j=1;j<=m+1;j++){
			if(stack[top]<d[i][j]){
				stack[++top]=d[i][j];
				w[top]=1;
				continue;
			}
			a=0;
			while(stack[top]>d[i][j]&&top>0){
				a+=w[top];
				ans=max(ans,stack[top]*a);
				top--;
			}
			w[++top]=a+1;
			stack[top]=d[i][j];
		}
	}
	cout<<3*ans;
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


