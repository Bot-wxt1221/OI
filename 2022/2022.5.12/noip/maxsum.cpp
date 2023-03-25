#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int read(){
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
signed main(){
	freopen("maxsum.in","r",stdin);
	freopen("maxsum.out","w",stdout);
	int T=read(),j=1;
	while(T--){
		int n=read();
		int Nowq=0,Max=0,Minq=0,Minqy,Maxqy,Minqx=1;
		for(int i=1;i<=n;i++){
			Nowq+=read();
			if(Nowq-Minq>Max){
				Minqy=Minqx;
				Maxqy=i;
				Max=Nowq-Minq;
			}
			if(Nowq<Minq){
				Minq=Nowq;
				Minqx=i+1;
			}
		}
		printf("Case %d:\n",j++);
		printf("%d ",Max);
		printf("%d ",Minqy);
		printf("%d\n\n",Maxqy);
//		printf("Case %d:\n%d %d %d\n\n",j++,Max,Minqy,Maxqy);
	}
	return 0;
}
/*
Anything about this program:
Type:
	热身 
Description:
	求最大区间和 
Example:
	1:
		In:
			2
			5 6 -1 5 4 -7
			7 0 6 -1 1 -6 7 -5
		Out:
			Case 1:
			14 1 4
			
			Case 2:
			7 1 6 
			
More:
	printf出现鬼畜现象 
*/


