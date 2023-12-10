#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 1000000007
inline int read();
int pw[2000005];
int pow(int x,int y){
  return pw[y];
}
int fir[1000005];
int nxt[2000005];
int v[2000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int maxsiz=0;
int max1,max2;
void dfs(int now,int fa,int *maxdep,int *maxdepi){
	int mdep1=0,mdepi1=now; 
	int mdep2=-0x3f3f3f3f3f3f3f3f,mdepi2=0; 
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    int aa,bb;
    dfs(v[i],now,&aa,&bb);
    if(aa>=mdep1){
      mdep2=mdep1;
      mdepi2=mdepi1;
      mdep1=aa;
      mdepi1=bb;
		}else if(aa>=mdep2){
			mdep2=aa;
      mdepi2=bb;
		}
  }
  *maxdep=mdep1+1;
  *maxdepi=mdepi1;
  if(maxsiz<(mdep1+mdep2)){
    maxsiz=(mdep1+mdep2);
    max1=mdepi1;
    max2=mdepi2;
  }
  return ;
}
class node1{
  public:
    int dis,i;
    node1 *to;
}dis1[1000005],dis2[1000005];
bool cmp(node1 a,node1 b){
  return a.dis==b.dis?(a.to->dis)>(b.to->dis):a.dis<b.dis;
}
void dfs2(int now,int fa,node1 *dis){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dis[v[i]].dis=dis[now].dis+1;
    dis[v[i]].i=v[i];
    dfs2(v[i],now,dis);
  }
  return ;
}
int limited[1000005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("tree9.in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  pw[0]=1;
  for(int i=1;i<=2*n;i++){
  	pw[i]=pw[i-1]*2%mod;
  } 
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
	int temp1,temp2;
  dfs(1,1,&temp1,&temp2);
  dfs2(max1,max1,dis1);
  dfs2(max2,max2,dis2);
  for(int i=1;i<=n;i++){
    dis2[i].to=&dis1[i];
  }
  int i1=1,i2=1;
  int mm=-0x3f3f3f3f3f3f3f3f;
  for(int i=1;i<=n;i++){
    if(dis1[i].dis==maxsiz&&dis2[i].dis==maxsiz){
      printf("%lld",(long long)((pow(2,n)*maxsiz)%mod));
      return 0;
    }
    if(dis1[i].dis>dis2[i].dis){
      std::swap(dis1[i].dis,dis2[i].dis);
    }
    mm=std::max(mm,dis1[i].dis);
  }
  std::sort(dis2+1,dis2+n+1,cmp);
  int ans=(mm*2)%mod;
  ans+=((pow(2,n-2)*maxsiz)%mod*2)%mod;
  for(int i=1;i<=n-2;i++){
//  	printf("%lld\n",(long long)(ans));
    ans+=(pow(2,i)*std::max(mm,dis2[i].dis))%mod;
    ans%=mod;
  }
  printf("%lld",(long long)(ans));
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

