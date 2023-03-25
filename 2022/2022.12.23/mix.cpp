#include <iostream>
#include <cstdio>
inline int read();
int w[35],c[35],p[35];
int dp[205];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("mix.in","r",stdin);
	freopen("mix.out","w",stdout);
	#endif
    int V=read();
    int n=read();
    for(int i=1;i<=n;i++){
        w[i]=read();
        c[i]=read();
        p[i]=read();
    }
    for(int i=1;i<=n;i++){
        if(p[i]==0||V<=p[i]*w[i]){
            for(int j=w[i];j<=V;j++){
                dp[j]=std::max(dp[j],dp[j-w[i]]+c[i]);
            }
        }else{
            int k=1;
            for(k=1;k<=p[i];){
                for(int j=V;j>=w[i]*k;j--){
                    dp[j]=std::max(dp[j],dp[j-w[i]*k]+c[i]*k);
                }
                p[i]-=k;
                k=k*2;
            }
            k=p[i];
            for(int j=V;j>=w[i]*k;j--){
                dp[j]=std::max(dp[j],dp[j-w[i]*k]+c[i]*k);
            }
        }
    }
    printf("%d",dp[V]);
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

