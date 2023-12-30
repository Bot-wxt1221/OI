#include <iostream>
#include <cstdio>
#include <random>
#define mod 1000000579ll
#define inv 576923411
#define mod2 100000687ll
inline int read();
namespace pro{
  inline int read();
  char temp[1000005];
  char temp2[1000005];
  long long pos[1000005];
  long long tree[1000005];
  long long tree2[1000005];
  int n;
  long long pow(long long x,long long y){
    if(y==0){
      return 1;
    }
    if(y%2==1){
      return (pow(x,y-1)*x)%mod;
    }else {
      long long temp=pow(x,y/2);
      return (temp*temp)%mod;
    }
  }
  int lowbit(int x){
    return (x)&(-x);
  }
  long long query(long long *tre,int x){
    long long ans=0;
    while(x>0){
      ans+=tre[x];
      ans%=mod;
      x-=lowbit(x);
    }
    return ans;
  }
  void add(long long *tre,int x,long long y){
    while(x<=n){
      tre[x]+=y;
      tre[x]%=mod;
      tre[x]+=mod;
      tre[x]%=mod;
      x+=lowbit(x);
    }
    return ;
  }
  int solve(){
    n=read();
    int q=read();
    scanf("%s",temp+1);
    for(int i=1;i<=n;i++){
      temp2[n-i+1]=temp[i];
      temp[i]-='a';
      temp2[n-i+1]-='a';
      pos[i]=pow(26,i-1)%mod;
      add(tree,i,(pos[i]*temp[i])%mod);
    }
    for(int i=1;i<=n;i++){
      add(tree2,i,(pos[i]*temp2[i])%mod);
    }
    for(int i=1;i<=q;i++){
      int op=read();
      switch (op) {
        case 1:{
          int x=read();
          char c;
          std::cin>>c;
          add(tree,x,(-pos[x]*temp[x]+mod)%mod);
          add(tree2,n-x+1,(-pos[n-x+1]*temp2[n-x+1]+mod)%mod);
          temp[x]=temp2[n-x+1]=c-'a';
          add(tree,x,(pos[x]*temp[x])%mod);
          add(tree2,n-x+1,(pos[n-x+1]*temp2[n-x+1])%mod);
          break;
      }
        case 2:{
                 int l=read();
                 int r=read();
                if((((query(tree,r)-query(tree,l-1)+mod)%mod)*pow(inv,l-1))%mod==(((query(tree2,(n-l+1))-query(tree2,(n-r))+mod)%mod)*pow(inv,(n-r)))%mod&&temp[r]==temp2[n-l+1]&&temp[l]==temp2[n-r+1]){
                   printf("Yes\n");
                 }else{
                   printf("No\n");
                 }
                 break;
               }
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


