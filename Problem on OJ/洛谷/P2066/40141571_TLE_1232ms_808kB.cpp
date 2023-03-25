#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char a[20005];
char b[20005];
int dp[20005][20005];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	#endif
    int sa=read(),sb;
	sb=read();
	for(int i=1;i<=sa;i++){
		a[i]=read();
	}
	for(int i=1;i<=sb;i++){
		a[i]=read();
	}
    for(int i=1;i<=sa;i++){
        for(int j=1;j<=sb;j++){
            if(a[i]==b[j]){
                dp[i][j]=std::max(dp[i][j],dp[i-1][j-1]+1);
            }
            dp[i][j]=std::max(dp[i][j],std::max(dp[i][j-1],dp[i-1][j]));
        }
    }
    printf("%d",dp[sa][sb]);
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

