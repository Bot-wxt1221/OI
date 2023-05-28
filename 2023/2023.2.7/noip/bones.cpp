#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
inline int read();
int a[10005];
int dp[10005];
int b[10005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("bones.in","r",stdin);
	freopen("bones.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int _min=0;
    int now=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        b[i]=read();
        sum+=b[i];
        now+=a[i];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[abs(now)]=0;
    for(int i=1;i<=n;i++){
        if(a[i]-b[i]<0)
            for(int j=sum;j>=0;j--){
                if(j-b[i]+a[i]<0){
                    continue;
                }
                dp[j]=std::min(dp[j],dp[j-b[i]+a[i]]+1);
            }
        else
            for(int j=0;j<=sum;j++){
                if(j-b[i]+a[i]<0){
                    continue;
                }
                dp[j]=std::min(dp[j],dp[j-b[i]+a[i]]+1);
            }
    }
    int ansi=0;

    int ansto=0x3f3f3f3f;
    for(int i=1;i<=sum;i++){
        int bsum=sum-i;
        int temp=abs(sum-2*i);
        if(dp[i]==0x3f3f3f3f){
            continue;
        }
        if(temp<ansto){
            ansto=temp;
            ansi=i;
        }else if(temp==ansto){
            if(dp[i]<dp[ansi]){
                ansi=i;
            }
        }
    }
    printf("%d %d",ansto,dp[ansi]);
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

