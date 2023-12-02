#include <iostream>
#include <cstdio>
inline int read();
int dp[5005][2];
char a[5005];
char a2[5050];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen("palindrome.in","r",stdin);
	// freopen("palindrome.out","w",stdout);
	#endif
    int n=read();
    scanf("%s",a+1);
    for(int i=1;i<=n;i++){
        a2[n-i+1]=a[i];
    }
    // memset()
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[j][i%2]=0;
            if(a[i]==a2[j]){
                dp[j][i%2]=std::max(dp[j][i%2],dp[j-1][(i-1)%2]+1);
            }
            dp[j][i%2]=std::max(dp[j][i%2],dp[j][(i-1)%2]);
            dp[j][i%2]=std::max(dp[j][i%2],dp[j-1][(i)%2]);
        }
    }
    printf("%d",n-dp[n][n%2]);
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

