#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
int n=10000010;
int dp[10000005];
bitset<10000005>a;
bool check(int a){
	while(a>0){
		if(a%10==7){
			return 1;
		}
		a=a/10;
	}
	return 0;
}
void init(){
	int ls=0;
	for(int i=1;i<=n;i++){
		if(a[i]){
			continue ;
		}
		if(check(i)){
			for(int j=i;j<=n;j+=i){
				a[j]=1;
			}
			continue ;
		}
		dp[ls]=i;
		ls=i;
	}
	return ;
}
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
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	init();
	int T=read();
	while(T--){
		int i=read();
		if(a[i]){
			printf("-1\n");
		}else{
			printf("%d\n",dp[i]);
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


