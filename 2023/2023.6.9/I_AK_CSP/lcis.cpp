#include <iostream>
#include <cstdio>
inline int read();
int a[3005];
int b[3005];
int dp[3005][3005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("lcis.in","r",stdin);
	freopen("lcis.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        b[i]=read();
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int _max=1;
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(a[i]==b[j]){
                dp[i][j]=std::max(dp[i][j],_max);
            }else if(a[i]>b[j]){
                _max=std::max(dp[i-1][j]+1,_max);
            }
            ans=std::max(ans,dp[i][j]);
        }
    }
    printf("%d",ans);
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


