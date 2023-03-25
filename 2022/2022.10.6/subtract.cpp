#include <iostream>
#include <cstdio>
using namespace std;
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
bool check(long long maxn,long long S,int k,int type)
{
	if (type==0)
		return (maxn*((long long)k-1LL)<=S);
	return ((S-maxn*((long long)k-1LL)>=0)&&(S+maxn)%k==0LL);
}
int main(){
	freopen("subtract.in","r",stdin);
	freopen("subtract.out","w",stdout);
	int T=read();
	while(T--){
		register int n=read();
		register int k=read();
		register int t=read();
		register long long temp=0;
		register long long _max=0;
		for(register int i=1;i<=n;i++){
			register long long r=read();
			temp+=r;
			_max=max(_max,r);
		}
		temp-=_max;
		bool ans=check(_max,temp,k,t);
		if(ans){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
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



