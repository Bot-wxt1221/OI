#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define int long long
inline int read();
int inti[505][105];
int out[505][105];
int fir[5005];
int nxt[200005];
int v[200005];
int ti[200005];
int bel[200005];
int now;
int dp[505][300][10];
bool sure[505][300][10];
class node{
  public:
    int num,sta,now;
    int data;
    node (int x=0,int y=0,int z=0,int zz=0){
      num=x;
      sta=y;
      now=z;
      data=zz;
      return ;
    }
};
bool operator < (node a,node b){
  return a.data>b.data;
}
std::priority_queue<node>qu;
void add(int x,int y,int z,int xx){
  bel[++now]=xx;
  ti[now]=z;
  v[now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
  int n=read(),k;
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  k=read();
  for(int i=1;i<=k;i++){
    for(int j=1;j<=n;j++){
      inti[j][i]=read();
    }
    for(int j=1;j<=n;j++){
      out[j][i]=read();
    }
    int mt=read();
    for(int j=1;j<=mt;j++){
      int u=read(),v,w;
      v=read();
      w=read();
      add(u,v,w,i);
      add(v,u,w,i);
    }
  }
  memset(dp,0x3f,sizeof(dp));
  for(int i=1;i<=k;i++){
    dp[1][(1<<(i-1))][i]=inti[1][i];
    qu.push(node(1,(1<<(i-1)),i,inti[1][i]));
  }
  while(qu.size()>0){
    node tt=qu.top();
    qu.pop();
    while(qu.size()>0&&sure[tt.num][tt.sta][tt.now]){
      tt=qu.top();
      qu.pop();
    }
    if(sure[tt.num][tt.sta][tt.now]){
      break;
    }
    sure[tt.num][tt.sta][tt.now]=1;
    for(int i=fir[tt.num];i!=-1;i=nxt[i]){
      if(bel[i]==tt.now){
        //dp[v[i]][tt.sta][tt.now]=std::min(dp[v[i]][tt.sta][tt.now],dp[tt.num][tt.sta][tt.now]+w[i]);
        if(dp[tt.num][tt.sta][tt.now]+ti[i]<dp[v[i]][tt.sta][tt.now]){
          dp[v[i]][tt.sta][tt.now]=dp[tt.num][tt.sta][tt.now]+ti[i];
          qu.push(node(v[i],tt.sta,tt.now,dp[v[i]][tt.sta][tt.now]));
        }
      }else if((tt.sta&(1<<(bel[i]-1)))==0){
        //dp[v[i]][tt.sta|(1<<(bel[i]-1))][bel[i]]=std::min(dp[v[i]][tt.sta|(1<<(bel[i]-1))][bel[i]],tt.data+out[tt.num][tt.now]+inti[tt.num][bel[i]]+ti[i]);
        if(dp[v[i]][tt.sta|(1<<(bel[i]-1))][bel[i]]>tt.data+out[tt.num][tt.now]+inti[tt.num][bel[i]]+ti[i]){
          dp[v[i]][tt.sta|(1<<(bel[i]-1))][bel[i]]=tt.data+out[tt.num][tt.now]+inti[tt.num][bel[i]]+ti[i];
          qu.push(node(v[i],(tt.sta|(1<<(bel[i]-1))),bel[i],dp[v[i]][tt.sta|(1<<(bel[i]-1))][bel[i]]));
        }
      }
    }
  }
  int ans=0x3f3f3f3f3f3f3f3fll;
  for(int i=1;i<=k;i++){
    for(int sta=0;sta<(1<<k);sta++){
      ans=std::min(ans,dp[n][sta][i]+out[n][i]);
    }
  }
  printf("%lld",ans);
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


