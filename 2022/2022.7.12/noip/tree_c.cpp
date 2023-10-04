#include <iostream>
#include <cstdio>
#include <cstring>
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
char a[1005];
int main(){
	freopen("tree_c.in","r",stdin);
	freopen("tree_c.out","w",stdout);
	scanf("%s",a+1);
	int siz=strlen(a+1);
	for(int i=siz+1;i<=siz*2+100;i++){
		a[i]='#';
	}
	for(int i=1;i<=siz;i++){
		if(a[i*2]=='#'&&a[i*2+1]=='#'){
			
		}else if(a[i*2]!='#'&&a[i*2+1]!='#'){
			
		}else{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
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



