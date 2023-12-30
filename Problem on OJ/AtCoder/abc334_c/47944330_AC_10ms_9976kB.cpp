// LUOGU_RID: 140910595
#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
namespace pro{
  inline int read();
  int cnt[200005];
  int cnt2[200005];
  int suf1[200005];
  int suf2[200005];
  int kk2;
  int solve(){
    int n=read(),k;
    k=read();
    for(int i=1;i<=k;i++){
      cnt[i]=read();
    }
    std::sort(cnt+1,cnt+k+1);
    int fans=0;
    int lans=0;
    int tt=0;
    int ll=0;
    int op=0;
    for(int i=1;i<=k;i++){
      if(cnt[i]!=cnt[i-1]&&cnt[i]!=cnt[i+1]){
        cnt2[++kk2]=cnt[i];
      }
    }
    for(int i=1;i<=k;i++){
      if(cnt[i]==cnt[i-1]||cnt[i]==cnt[i+1]){
        continue;
      }
      if(op==0){
        op^=1;
        ll=i;
      }else{
        op^=1;
        tt+=cnt[i]-cnt[ll];
        lans=cnt[i]-cnt[ll];
        if(!fans){
          fans=cnt[i]-cnt[ll];
        }
      }
    }
    if(k%2==0){
      printf("%lld",tt);
    }else{
      suf1[1]=suf2[1]=0x3f3f3f3f;
      for(int i=2;i<=k;i++){
        suf1[i]=suf1[i-2]+cnt[i]-cnt[i-1];
      }
      for(int i=k-1;i>=1;i--){
        suf2[i]=suf2[i+2]+cnt[i+1]-cnt[i];
      }
      int tt=0x3f3f3f3f;
      for(int i=1;i<=k;i++){
        if(i%2==0){
          tt=std::min(tt,suf1[i-2]+suf2[i+2]+(cnt[i+1]-cnt[i-1]));
        }else{
          tt=std::min(tt,suf1[i-1]+suf2[i+1]);
        }
      }
      printf("%lld",tt);
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


