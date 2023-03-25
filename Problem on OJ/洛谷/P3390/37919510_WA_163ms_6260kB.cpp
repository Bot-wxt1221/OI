#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
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
class node{
	public:
		int map[205][205]; 
		node(){
			memset(map,0,sizeof(map));
			return ;
		}
		node operator * (node &b){
			node c;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						c.map[i][j]+=map[i][k]*b.map[k][j];
						c.map[i][j]%=1000000007;
					}
				}
			}
			return c;
		}
}input;

node caalc(int m){
	if(m==1){
		return input;
	}
	if(m%2==1){
		return caalc(m-1)*input;
	}else{
		node a=caalc(m/2);
		return a*a;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			input.map[i][j]=read();
		}
	}
	int x=read();
	node temp=caalc(x);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lld ",temp.map[i][j]); 
		}
		printf("\n"); 
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

