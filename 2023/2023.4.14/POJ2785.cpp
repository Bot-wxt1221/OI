#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int anss[16000006];
int a[4005],b[4005],c[4005],d[4005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	int T=read();
	while(T--){
		int n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			b[i]=read();
			c[i]=read();
			d[i]=read();
		}
		int temp=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				anss[++temp]=a[i]+b[j];
			}
		}
		std::sort(anss+1,anss+temp+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(std::lower_bound(anss+1,anss+temp+1,-c[i]-d[j])!=anss+temp+1)
					ans+=(std::upper_bound(anss+1,anss+temp+1,-c[i]-d[j])-std::lower_bound(anss+1,anss+temp+1,-c[i]-d[j]));
			}
		}
		printf("%lld\n",ans);
		if(T!=0){
			printf("\n");
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


