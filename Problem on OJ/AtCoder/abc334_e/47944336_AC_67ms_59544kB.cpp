#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#define int long long
inline int read();
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int temp=pow(x,y/2);
    return (temp*temp)%998244353ll;
  }
  return (pow(x,y-1)*x)%998244353ll;
}
int gcd(int x,int y){
  if(x>y){
    std::swap(x,y);
  }
  if(x==0){
    return y;
  }
  return gcd(y%x,x);
}
namespace pro{
  inline int read();
  std::map<int,int>a;
  char map[1005][1005];
  int mp[1005][1005];
  int h,w;
  int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
  void dfs(int xx,int yy,int co){
    if(xx<=0||yy<=0||xx>h||yy>w){
      return ;
    }
    if(mp[xx][yy]||map[xx][yy]=='.'){
      return ;
    }
    mp[xx][yy]=co;
    for(int i=0;i<4;i++){
      dfs(xx+to[i][0],yy+to[i][1],co);
    }
  }
  int solve(){
    h=read();
    w=read();
    for(int i=1;i<=h;i++){
      scanf("%s",map[i]+1);
    }
    int cl=0;
    for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
        if(map[i][j]=='#'&&mp[i][j]==0){
          dfs(i,j,++cl);
        }
      }
    }
    int ans=0;
    int bb=0;
    for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
        if(map[i][j]=='#'){
          continue;
        }
        bb++;
        int tt=0;
        a=std::map<int,int>();
        for(int k=0;k<4;k++){
          if(map[i+to[k][0]][j+to[k][1]]=='.'||((i+to[k][0])<=0)||(i+to[k][0]>h)||(j+to[k][1]<=0)||(j+to[k][1]>w)){
            continue;
          }
          if(a[mp[i+to[k][0]][j+to[k][1]]]==0){
            tt++;
          }
          a[mp[i+to[k][0]][j+to[k][1]]]=1;
        }
        if(tt==0){
          ans+=cl+1;
        }
        if(tt==1){
          ans+=cl;
        }
        if(tt==2){
          ans+=cl-1;
        }
        if(tt==3){
          ans+=cl-2;
        }
        if(tt==4){
          ans+=cl-3;
        }
        ans%=998244353ll;
      }
    }
    printf("%lld",(ans*pow(bb,998244353ll-2ll))%998244353ll);
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


