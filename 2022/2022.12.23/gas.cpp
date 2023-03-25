#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int a[1006],b[1005],c[1006];
int dp[30][85];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("gas.in","r",stdin);
	freopen("gas.out","w",stdout);
	#endif
    int m=read(),n=read();
    int k=read();
    for(int i=1;i<=k;i++){
        a[i]=read();
        b[i]=read();
        c[i]=read();
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=k;i++){
        for(int x=m;x>=0;x--){
            for(int y=n;y>=0;y--){
                int ax=std::min(m,x+a[i]);
                int ay=std::min(n,y+b[i]);
                dp[ax][ay]=std::min(dp[x][y]+c[i],dp[ax][ay]);
            }
        }
    }
    printf("%d",dp[m][n]);
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

