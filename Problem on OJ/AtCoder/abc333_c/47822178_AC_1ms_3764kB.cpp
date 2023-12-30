#include <iostream>
#include <cstdio>
inline int read();
namespace pro{
  inline int read();
  int solve(){
    int n=read();
    int aa=0;
    int i;
    for(i=20;i>=1;i--){
      if(n>((i-1)*(i-2)*(i-3)/6+(i-1)*(i-2)+(i-1))){
        n-=((i-1)*(i-2)*(i-3))/6+(i-1)*(i-1);
        aa=i;
        break;
      }
    }
    int bb;
    for(;i>=1;i--){
      if(n>((i-1)*(i-2)/2+(i-1))){
        n-=((i-1)*(i-2)/2+(i-1));
        bb=i;
        break;
      }
    }
    for(int i=20;i>=1;i--){
      if(i<=aa)
        printf("%d",(i<=aa)+(i<=bb)+(i<=n));
    }
    return 0; 
  }
};
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	return pro::solve();
}
inline int pro::read(){
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


