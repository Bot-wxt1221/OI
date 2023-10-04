#include <iostream>
#include <cstdio>
inline int read();
int a[1005];
int f[1005];
int dp1[1005];
int dp2[1005];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        dp1[i]=1;
        for(int j=1;j<i;j++){
            if(a[i]>a[j]){
                dp1[i]=std::max(dp1[i],dp1[j]+1);
            }
        }
    }
    for(int i=n;i>=1;i--){
        dp2[i]=1;
        for(int j=n;j>i;j--){
            if(a[i]>a[j]){
                dp2[i]=std::max(dp2[i],dp2[j]+1);
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        ans=std::min(ans,n-dp1[i]-dp2[i]+1);
    }
    printf("%d",n-ans);
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