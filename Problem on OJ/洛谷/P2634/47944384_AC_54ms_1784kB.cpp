#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm> 
inline int read();
namespace pro{
  std::queue<int>qu;
  int fir[40005];
  int nxt[80005];
  int v[80005];
  int w[80005];
  bool vised[80005];
  int now,k;
  int df[5];
  int siz[40005];
  int maxson[40005];
  int fd;
  int tot;
  void heavy(int now,int fa) { 
    siz[now]=1;
    maxson[now]=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(vised[v[i]]||v[i]==fa){
        continue;
      }
      heavy(v[i],now);
      maxson[now]=std::max(maxson[now],siz[v[i]]);
      siz[now]+=siz[v[i]];
    }
    maxson[now]=std::max(maxson[now],tot-maxson[now]);
    if(maxson[now]<maxson[fd]){
      fd=now;
    }
    return ;
  }
  int cnt;
  int dis[40005];
  int dd[40006];
  void ans(int now,int fa){
    dd[++cnt]=dis[now];
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(vised[v[i]]||v[i]==fa){
        continue;
      }
      dis[v[i]]=dis[now]+w[i];
      ans(v[i],now);
    }
    return ;
  }
  int dddf[20005];
  int anscnt=0;
  void dfs(int now,int fa){
    vised[now]=1;
    cnt=0;
    dddf[0]=df[0]=1;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(vised[v[i]]||fa==v[i]){
        continue;
    }
      dis[v[i]]=w[i];
      cnt=0;
      ans(v[i],now);
      for(int j=1;j<=cnt;j++){
        dd[j]%=3;
        for(int kkk=0;kkk<3;kkk++){
          df[(dd[j]+kkk)%3]+=dddf[kkk];
        }
        
      }
      for(int j=1;j<=cnt;j++){
      	dddf[dd[j]]++;
	  }
    }
    dddf[0]=dddf[1]=dddf[2]=0;
    anscnt+=df[0]*2-1;
  df[0]=df[1]=df[2]=df[3]=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa||vised[v[i]]){
        continue;
      }
      tot=siz[v[i]];
      fd=0;
      maxson[fd]=0x3f3f3f3f;
      heavy(v[i],now);
      heavy(fd,fd);
      dfs(fd,fd);
    }
    return ; 
  }
  void add(int x,int y,int z){
    v[++now]=y;
    w[now]=z;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
  }
  int main(){
    int n=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
    }
    for(int i=1;i<n;i++){
      int u=read(),v;
      v=read();
      int w=read();
      add(u,v,w);
      add(v,u,w);
    }
    dfs(1,1);
    int tott=(n)*(n);
    int gg=std::__gcd(tott,anscnt);
	tott/=gg;
	anscnt/=gg;
    printf("%d/%d",anscnt,tott);
    return 0;
  }
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
    
  return pro::main();
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


