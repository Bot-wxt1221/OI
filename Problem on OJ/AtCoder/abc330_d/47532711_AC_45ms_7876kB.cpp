#include <iostream>
#include <cstdio>
#define int long long
inline int read();
namespace pro{
  inline int read();
  char s[2005][2005];
  int a[2005];
  int b[2005];
  int solve(){
    int n=read();
    for(int i=1;i<=n;i++){
      scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(s[i][j]=='o'){
          a[i]++;
          b[j]++;
        }
      }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(s[i][j]=='o')
          ans+=(a[i]-1)*(b[j]-1);
      }
    }
    printf("%lld",ans);
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


