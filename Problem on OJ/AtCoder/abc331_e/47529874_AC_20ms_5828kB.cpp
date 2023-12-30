#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
namespace pro{
  inline int read();
  int a[100005];
  bool used[100005];
  class node{
    public:
      int x,y;
      node (int xx=0,int yy=0){
        x=xx;
        y=yy;
        return ;
      }
  }b[100005];
  bool cmp(node a,node b){
    return a.x>b.x;
  }
  class node2{
    public:
      int c,l;
      node2(int xx=0,int yy=0){
        c=xx;
        l=yy;
        return ;
      }
  }que[100005];
  bool cmp2(node2 a,node2 b){
    return a.c<b.c;
  }
  int solve(){
    int n=read(),m;
    m=read();
    int l=read();
    int ans=0;
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    for(int i=1;i<=m;i++){
      b[i].x=read();
      b[i].y=i;
    }
    std::sort(b+1,b+m+1,cmp);
    for(int i=1;i<=l;i++){
      que[i].c=read();
      que[i].l=read();
    }
    std::sort(que+1,que+l+1,cmp2);
    int quenow=1;
    for(int i=1;i<=n;i++){
      int bknow=quenow;
      while(que[quenow].c==i){
        quenow++;
        used[que[quenow-1].l]=1;
      }
      int tt=1;
      while(used[b[tt].y]&&tt<=n){
        tt++;
      }
      if(tt<=n){
        ans=std::max(ans,b[tt].x+a[i]);
      }
      for(int j=bknow;j<quenow;j++){
        used[que[j].l]=0;
      }
    }
    printf("%d",ans);
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


