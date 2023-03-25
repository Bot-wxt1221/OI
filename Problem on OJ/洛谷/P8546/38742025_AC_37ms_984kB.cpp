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
char a[1005][1005];
int dp[1005][1005][2];
int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]=='1'){
                dp[i][j][0]=dp[i-1][j-1][0]+1;
                dp[i][j][1]=dp[i-1][j+1][1]+1;
            }
        }
    }
    int ans=0;
    for(int m=1;m<n;m++){
        for(int i=1;i+m<=n;i++){
            for(int j=1;j+m<=n;j++){
                if(dp[i+m][j+m][0]>=m+1&&dp[i+m][j][1]>=m+1){
                    ans++;
                }
            }
        }
    }
    printf("%d",ans);
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


