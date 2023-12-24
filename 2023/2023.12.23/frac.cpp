#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int cho[20];
int tcho[20];
int ra=0;
int rb=0;
bool del[30];
char numa[30];
int cnta;
char numb[30];
int cntb;
int ansa;
int ansb;
void dfs(int now){
	if(now==cnta+1){
		int aa=0;
		for(int i=0;i<10;i++){
			tcho[i]=cho[i];
		}
		for(int i=cnta;i>=1;i--){
			if(!del[i]){
				aa=aa*10+numa[i];
			}
		}
		if(aa==0){
			return ;
		}
		if(aa%ra!=0||aa==0){
			return ; 
		}
		int tb=(aa/ra)*rb;
		for(int i=1;i<=cntb;i++){
			if(tb%10==numb[i]){
				tb/=10;	
				continue;
			}
			tcho[numb[i]]--;
			if(tcho[numb[i]]<0){
				return ;
			}
		}
		if(aa<ansa){
			ansa=aa;
			ansb=(aa/ra)*rb;
		}
		return ;
	}
	//no
	dfs(now+1);
	//yes
	del[now]=1;
	cho[numa[now]]++;
	dfs(now+1);
	del[now]=0;
	cho[numa[now]]--;
}
int gcd(int __n,int __m){
	while (__n != 0)
	{
	  int __t = __m % __n;
	  __m = __n;
	  __n = __t;
	}
      return __m;
}
signed main(){
//	#ifdef ONLINE_JUDGE
//	#else
//	freopen("frac.in","r",stdin);
//	freopen("frac.out","w",stdout);
//	#endif
    int T=read();
    while(T--){
    	int a=read();
    	int aa=a;
    	cnta=0;
    	cntb=0;
    	while(aa>0){
    		numa[++cnta]=aa%10;
    		aa/=10;
		}
    	int b=read();
    	int bb=b;
    	while(bb>0){
    		numb[++cntb]=bb%10;
    		bb/=10;
		}
		int gg=gcd(a,b);
		ra=a/gg;
		rb=b/gg;
		ansa=0x3f3f3f3f3f3f3f3f;
		ansb=0x3f3f3f3f3f3f3f3f;
    	dfs(1);
    	printf("%lld %lld\n",ansa,ansb); 
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


