#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
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
int n;
int a[1000005],b[1000005];
int top=0;
int sta[1000005];
int main(){
	freopen("disk.in","r",stdin);
	freopen("disk.out","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF){
		top=0;
		for(int i=1;i<=n;i++){
			a[i]=b[i]=read();
		}
		sort(a+1,a+n+1);
		int bi=1;
		for(int i=1;i<=n;i++){
			while(top!=0&&sta[top-1]==b[bi]&&bi<=n){
				bi++;
				top--;
			}
			sta[top++]=a[i];
		}
		while(top!=0&&sta[top-1]==b[bi]&&bi<=n){
				bi++;
				top--;
			}
		if(bi>n){
			printf("Y\n");
		}else{
			printf("J\n");
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



