#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[100005];
int temp[100005];
int ans;
void qsort(int l,int r){
	if(l>=r){
		return; 
	}
  int mid=(l+r)/2;
  qsort(l,mid);
  qsort(mid+1,r);
  int ll=l,rl=mid+1;
  int tt=0;
  while(ll<=mid&&rl<=r){
    if(a[ll]<=a[rl]){
      temp[++tt]=a[ll];
      ll++;
      ans+=(r-rl+1);
    }else{
      temp[++tt]=a[rl];
      rl++;
      
    }
  }
  while(ll<=mid){
  	temp[++tt]=a[ll];
    ll++;
    ans+=(r-rl+1);
  }
  while(rl<=r){
  	temp[++tt]=a[rl];
    rl++;
  }
  for(int i=l;i<=r;i++){
    a[i]=temp[i-l+1];
  }
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),k;
  k=read();
  for(int i=1;i<=n;i++){
    a[i]=read()-k;
  }
  for(int i=1;i<=n;i++){
    a[i]+=a[i-1];
  }
  for(int i=n;i>=1;i--){
  	a[i+1]=a[i];
  }
  a[1]=0;
  qsort(1,n+1);
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
