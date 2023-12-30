#include <iostream>
#include <cstdio>
inline int read();
namespace pro{
  inline int read();
  int n,W;
  int w[255];
  int t[255];
  long double dp[1005];
  bool check(long double mid){
    for(int i=1;i<=W;i++){
      dp[i]=-0x3f3f3f3f;
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
      for(int j=W;j>=0;j--){
        dp[std::min(j+w[i],W)]=std::max(dp[std::min(j+w[i],W)],dp[j]+(-w[i]*mid+t[i]));
      }
    }
    return dp[W]>0;
  }
  int solve(){
    n=read();
    W=read();
    long double L=0,R=0;
    for(int i=1;i<=n;i++){
      w[i]=read();
      t[i]=read();
      R+=w[i];
      R+=t[i];
    }
    for(int i=1;i<=100;i++){
      long double mid=(L+R)/2;
      if(check(mid)){
        L=mid;
      }else{
        R=mid;
      }
    }
    printf("%d\n",int(L*1000));
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


