#include <iostream>
#include <cstdio>
#include <queue>
#define mod 998244353
#define int long long
inline int read();
int a[505][505];
int n;
int two(int x,int y){
  return (x-1)*n+y;
}
int sm[250005];
int fir[250005];
int nxt[2000005];
int v[2000005];
int now=0;
int in[250005];
void add(int x,int y){
  v[++now]=y;
  in[y]++;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int xishu[250005];
namespace fan{
  int fir[250005];
  int nxt[2000005];
  int v[2000005];
  int in[250005];
  int now;
  std::queue<int>qu;
  void top(){
    for(int i=1;i<=n*n;i++){
      if(in[i]==0){
        qu.push(i);
      }
    }
    while(qu.size()>0){
      int tt=qu.front();
      qu.pop();
      xishu[tt]+=sm[tt];
      xishu[tt]%=mod;
      for(int i=fir[tt];i!=-1;i=nxt[i]){
        xishu[v[i]]+=xishu[tt];
        xishu[v[i]]%=mod;
        in[v[i]]--;
        if(in[v[i]]==0){
          qu.push(v[i]);
        }
      }
    }
    return ;
  }
  void add(int x,int y){
    v[++now]=y;
    in[y]++;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
  }
};
std::queue<int>qu;
int dp[250005];
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
  #endif
  n=read();
  for(int i=1;i<=n*n;i++){
    fir[i]=fan::fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      a[i][j]=read();
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      sm[two(i,j)]++;
      for(int k=0;k<4;k++){
        int nx=i+to[k][0];
        int ny=j+to[k][1];
        if(nx<=0||ny<=0||nx>n||ny>n){
          continue;
        }
        if(a[nx][ny]<=a[i][j]){
          sm[two(i,j)]++;
        }else{
          add(two(i,j),(two(nx,ny)));
          fan::add(two(nx,ny),two(i,j));
        }
      }
    }
  }
  fan::top();
  for(int i=1;i<=n*n;i++){
    if(in[i]==0){
      qu.push(i);
    }
    dp[i]=1;
  }
 int ans=0;
  while(qu.size()>0){
    int tt=qu.front();
    qu.pop();
    ans+=(sm[tt]*dp[tt])%mod;
    for(int i=fir[tt];i!=-1;i=nxt[i]){
      dp[v[i]]+=dp[tt];
      dp[v[i]]%=mod;
      in[v[i]]--;
      if(in[v[i]]==0){
        qu.push(v[i]);
      }
    }
  }
  int q=read();
//  printf("%lld\n",ans);
  for(int i=1;i<=q;i++){
    int x=read();
    int y=read();
    int cntt=0;
    for(int k=0;k<4;k++){
      int nx=x+to[k][0];
      int ny=y+to[k][1];
      if(nx<=0||ny<=0||nx>n||ny>n){
        continue;
      }
      if(a[nx][ny]<a[x][y]){
        cntt+=dp[two(nx,ny)]; 
        cntt%=mod;
      }
    }
    int ansss=(((((((ans+1)%mod-((dp[two(x,y)]*xishu[two(x,y)]))%mod))%mod+mod))%mod)+cntt)%mod;
    ansss+=mod;
    ansss%=mod;
    printf("%lld\n",ansss);
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


