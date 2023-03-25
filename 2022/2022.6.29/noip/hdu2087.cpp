#include <iostream>
#include <cstdio>
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
char a[1005];
char b[1005];
int dp[1005];
bool cmp(char a[],char b[],int size){
	for(int i=0;i<size;i++){
		if(a[i]!=b[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("hdu2087.in","r",stdin);
	freopen("hdu2087.out","w",stdout);
	scanf("%s",a);
	while(a[1]!='\0'||a[0]!='#'){
		scanf("%s",b);
		int sa=strlen(a),sb=strlen(b);
		memset(dp,0,sizeof(dp));
		for(int i=sb-1;i<sa;i++){
			if(cmp(a+i-sb+1,b,sb)){
				dp[i]=dp[i-sb]+1;
			}else{
				dp[i]=dp[i-1];
			}
		}
		printf("%d\n",dp[sa-1]);
		scanf("%s",a);
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



