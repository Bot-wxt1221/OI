#include <iostream>
#include <cstdio>
#include <set>
inline int read();
std::set<int>a;
int seq[200005];
int cnt[200005];
namespace pro{
  inline int read();
  int solve(){
    int n=read(),q;
    q=read();
    for(int i=0;i<=n+1;i++){
      a.insert(i);
    }
    for(int i=1;i<=n;i++){
      seq[i]=read();
      if(seq[i]>n){
        seq[i]=n+1;
      }
      cnt[seq[i]]++;
      if(cnt[seq[i]]==1){
        a.erase(a.find(seq[i]));
      }
    }
    for(int i=1;i<=q;i++){
      int op=read();
      int x=read();
      cnt[seq[op]]--;
      if(cnt[seq[op]]==0){
        a.insert(seq[op]);
      }
      if(x>n){
        x=n+1;
      }
      seq[op]=x;
      cnt[x]++;
      if(cnt[x]==1){
        a.erase(a.find(x));
      }
      printf("%d\n",*a.begin());
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


