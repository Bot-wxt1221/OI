#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char a[205];
char b[205];
int dp[205][205];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	#endif
    scanf("%s",a+1);
    scanf("%s",b+1);
    int sa=strlen(a+1);
    int sb=strlen(b+1);
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

