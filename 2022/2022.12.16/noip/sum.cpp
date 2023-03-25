#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();
bool dp[2005];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	#endif
    int n=read();
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int a=read();
        for(int j=2005;j>=a;j--){
            dp[j]|=dp[j-a];
        }
    }
    int q=read();
    for(int i=1;i<=q;i++){
        int qu=read();
        if(dp[qu]==0)
            printf("no\n");
        else
            printf("yes\n");
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

