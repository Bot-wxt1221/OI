#include <iostream>
#include <cstdio>
#define int long long
inline int read();
namespace pro{
  inline int read();
  char temp[1005][1005];
  int sum[1005][1005];
  int getsum(int x,int y,int n){
    if(x==0||y==0){
      return 0;
    }
    return (y/n)*sum[x][n]+sum[x][y%n];
  }
  int sum2[1005];
  int solve(){
    int n=read(),q;
    q=read();
    for(int i=1;i<=n;i++){
      scanf("%s",temp[i]+1);
      for(int j=1;j<=n;j++){
        sum2[j]+=((temp[i][j]=='B'));
      }
    }
    for(int i=1;i<=n;i++){
      sum2[i]+=sum2[i-1];
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+((temp[i][j])=='B');
      }
    }
    for(int i=1;i<=q;i++){
      int a=read()+1;
      int b=read()+1;
      int c=read()+1;
      int d=read()+1;
      if((a-1)/n==(c-1)/n){
        a--;
        a%=n;
        a++;
        c--;
        c%=n;
        c++;
        printf("%lld\n",getsum(c,d,n)-getsum(c,b-1,n)-getsum(a-1,d,n)+getsum(a-1,b-1,n));

      }
      else{
        int tt=((c-1)/n-(a-1)/n-1);
        a--;
       a%=n;
       a++;
       c--;
        c%=n;
        c++;
        int ans=0;
        int bb=b;
        int dd=d;
        if((bb-1)/n==(dd-1)/n){
          bb--;
          bb%=n;
          bb++;
          dd--;
          dd%=n;
          dd++;
          ans=(sum2[dd]-sum2[bb-1]);
        }else{
          int ttt=(dd-1)/n-(bb-1)/n-1;
          bb--;
          bb%=n;
          bb++;
          dd--;
          dd%=n;
          dd++;
          ans=(sum2[n]-sum2[bb-1]+sum2[dd]+(ttt)*(sum2[n]));
        }
        printf("%lld\n",getsum(n,d,n)-getsum(n,b-1,n)-getsum(a-1,d,n)+getsum(a-1,b-1,n)+getsum(c,d,n)-getsum(c,b-1,n)+(tt)*(ans));
      }
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


