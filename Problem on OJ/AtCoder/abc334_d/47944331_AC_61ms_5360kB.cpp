#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
inline int read();
namespace pro{
  inline int read();
  int r[200005];
  int solve(){
    int n=read(),q;
    q=read();
    for(int i=1;i<=n;i++){
      r[i]=read();
    }
    std::sort(r+1,r+n+1);
    for(int i=1;i<=n;i++){
      r[i]+=r[i-1];
    }
    for(int i=1;i<=q;i++){
      int xx=read();
      printf("%ld\n",std::upper_bound(r+1,r+n+1,xx)-r-1);
    }
    return 0; 
  }
};
signed main(){
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


