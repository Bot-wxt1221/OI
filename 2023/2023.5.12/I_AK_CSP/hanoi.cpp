#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int f[55],xx;
void move_h(int done,int n,char x,char y,char z){
	if(n==1){
		printf("%d %c->%c",n,x,z);
		return ;
	}else{
		if(done+f[n-1]>=xx){
			move_h(done,n-1,x,z,y);
			return ;
		}else if(done+f[n-1]+1==xx){
			printf("%d %c->%c",n,x,z);
			return ;
		}else{
			move_h(done+f[n-1]+1,n-1,y,x,z);
			return ;
		}

	}
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("hanoi.in","r",stdin);
	freopen("hanoi.out","w",stdout);
	#endif
    int n=read();
	xx=read();
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]*2+1;
	}
	move_h(0,n,'a','c','b');
	return 0;
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


