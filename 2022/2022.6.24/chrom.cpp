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
bool vised[100000005];
int main(){
	freopen("chrom.in","r",stdin);
	freopen("chrom.out","w",stdout);
	int T=read();
	for(int i=2;i<=2000000;i++){
		if(vised[i])	continue;
		int j=i+i;
		while(j<=2000000){
			vised[j]=1;
			j+=i;
		}
	}
	while(T--){
		int k=read();
		if(k%2==0){
			printf("%d\n",k/2);
		}else if(k<2){
			printf("-1\n");
		}else{
			int ans=1;
			while(vised[k]==1){
				k-=2;
				ans++;
			}
			printf("%d\n",ans);
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


