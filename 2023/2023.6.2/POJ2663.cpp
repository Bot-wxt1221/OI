#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int f[35][5];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n;
	f[1][0]=0;
	f[1][1]=1;
	f[1][2]=0;
	f[2][0]=3;
	f[2][1]=0;
	f[2][2]=1;
	while(scanf("%lld",&n)!=EOF&&n!=-1){
        if(n==0){
            printf("1\n");
            continue;
        }
		for(int i=3;i<=n;i++){
			f[i][0]=f[i-1][1]*2+f[i-2][0];
			f[i][1]=f[i-1][0]+f[i-1][2];
			f[i][2]=f[i-1][1];
		}
		printf("%lld\n",f[n][0]);
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