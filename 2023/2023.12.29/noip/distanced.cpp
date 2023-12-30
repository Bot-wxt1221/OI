#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define int long long
inline int read();
class node{
  public:
    int x,a;
    node(int xx=0,int yy=0){
      x=xx;
      a=yy;
      return ;
    }
}d[7005];
int xx[7005];
bool operator < (node a,node b){
  return a.x<b.x;
}
std::priority_queue<int>qu;
int dp[405][405];
int ans[405];
int dp2[7005];
int dp3[7005];
signed main(){
//	#ifdef ONLINE_JUDGE
//	#else
	freopen("distanced3.in","r",stdin);
	freopen("distanced.out","w",stdout);
//	#endif
  int n=read();
  int t=read();
  for(int i=1;i<=n;i++){
    d[i].x=read();
  }
  bool pian=1;
  for(int i=1;i<=n;i++){
    d[i].a=read();
    if(d[i].a<0){
      pian=0;
    }
  }
  std::sort(d+1,d+n+1);
  for(int i=1;i<=n;i++){
    xx[i]=d[i].x;
  }
  if(pian==0){
      dp[1][1]=d[1].a;
      for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
          for(int k=1;k<=n;k++){
            if(d[i].x-d[j].x<=t){
              dp[i][k]=std::max(dp[i][k],dp[j][k]+d[i].a);
            }else{
              dp[i][k]=std::max(dp[i][k],dp[j][k-1]+d[i].a);
            }
            ans[k]=std::max(ans[k],dp[i][k]);
          }
        }
      }
      int _max=0;
      for(int i=1;i<=n;i++){
        _max=std::max(_max,ans[i]);
        printf("%lld ",_max);
      }
      return 0;
  }else{//a[i]>=0
    int ans=d[1].a;
    for(int i=2;i<=n;i++){
      if(d[i].x-d[i-1].x>t){
        qu.push(ans);
        ans=0;
      }
      ans+=d[i].a;
    }
    qu.push(ans);
  ans=0;
    for(int i=1;i<=n;i++){
      if(qu.size()>0){
        ans+=qu.top();
        qu.pop();
      }
      printf("%lld ",ans);
    }
    return 0;
  }
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


