#include <iostream>
#include <cstdio>
using namespace std;
inline int read();

int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    long long l=1,r=1000000000ll;
	while(r-l>=3){
		long long mid=(l+r)/2;
		printf("%d",mid);
		fflush(stdout);
		int res;
		scanf("%d",&res);
		if(res==0){
			return 0;
		}
		if(res==1){
			r=mid+1;
		}else if(res==-1){
			l=mid-1;
		}
	}
	for(int i=l;i<=r;i++){
		printf("%d",i);
		fflush(stdout);
		int res;
		scanf("%d",&res);
		if(res==0){
			return 0;
		}
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


