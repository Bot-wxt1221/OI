#include <iostream>
#include <cstdio>
#include <stack>
inline int read();
namespace pro{
  inline int read();
  std::stack<int>st[200005];
  bool used[200005];
  int t[200005];
  int solve(){
    int n=read();
    int now=0;
    int _max=0;
    for(int i=1;i<=n;i++){
      int t=read();
      pro::t[i]=t;
      int x=read();
      if(t==1){
        st[x].push(i);
      }else{
        if(st[x].size()==0){
          printf("-1");
          return 0;
        }else{
          used[st[x].top()]=1;
          st[x].pop();
        }
      }
    }
    for(int i=1;i<=n;i++){
      if(t[i]==1){
        if(used[i])
          now++;
        _max=std::max(_max,now);
      }else{
        now--;
      }
    }
    printf("%d\n",_max);
    for(int i=1;i<=n;i++){
      if(t[i]==1){
        printf("%d ",used[i]);
      }
    }
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


