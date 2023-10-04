#include <iostream>
#include <cstdio>
#define int long long
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
int const mod= 1000000007ll;
signed main(){
	freopen("cell.in","r",stdin);
	freopen("cell.out","w",stdout);
	int R=read();
	int C=read();
	int minT=read();
	int maxT=read();
	int ans=0;
	for(int n=3;n<=R;n++){
		int temp=0;
		for(int m=3;m<=C;m++){
			if((n+m)*2-4>maxT||minT>(n+m)*2-4){
				continue;
			}
			temp+=(((((((n-2)*(m-2))%mod))%mod)*(C-m+1))%mod);
			temp%=mod;
		}
		temp*=(R-n+1);
		temp%=mod;
		ans+=temp;
	}
	ans*=6;
	ans%=mod;
	printf("%lld",ans);
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


