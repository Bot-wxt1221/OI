#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
#define inv2 499122177
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2){
    return (pow(x,y-1)*x)%mod;
  }
  int temp=pow(x,y/2);
  return (temp*temp)%mod;
}
inline int read();
namespace pro{
  inline int read();
  int dp[3005][2];
  int solve(){
    int n=read();
    int op=0;
    dp[1][0]=1;
    for(int i=2;i<=n;i++){
      op^=1;
      int suml=0,sumr=0;
      int oo=inv2;
      oo%=mod;
      for(int j=i-1;j>=1;j--){
        oo*=inv2;
        oo%=mod;
        sumr+=(dp[j][op^1]*oo)%mod;
        sumr%=mod;
      }
      int tt=(pow(2,i));
      int ttt=tt;
      tt*=pow((pow(2,i)+mod-1)%mod,mod-2);
      tt%=mod;
      for(int j=1;j<=i;j++){
        dp[j][op]=(sumr*tt)%mod;
        dp[j][op]+=(suml*tt)%mod;
        dp[j][op]%=mod;
        sumr-=(dp[j][op^1]*pow(ttt,mod-2))%mod;
        sumr+=mod;
        sumr%=mod;
        sumr*=inv2;
        sumr%=mod;
        suml+=(dp[j][op^1]);
        suml%=mod;
        suml*=inv2;
        suml%=mod;
      }
    }
    for(int i=1;i<=n;i++){
      printf("%lld ",dp[i][op]);
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


