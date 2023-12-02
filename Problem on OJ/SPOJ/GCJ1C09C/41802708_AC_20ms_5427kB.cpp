#include <iostream>
#include <cstdio>
inline int read();
int a[105];
int dp[105][105];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("bribe.in","r",stdin);
	freopen("bribe.out","w",stdout);
	#endif
    int N=read();
    int ii=0;
    while(N--){
        ii++;
        int p=read();
        int q=read();
        for(int i=1;i<=q;i++){
            a[i]=read();
        }
        a[0]=0;
        a[q+1]=p+1;
        for(int siz=2;siz<=q+1;siz++){
            for(int i=0;i+siz<=q+1;i++){
                int j=i+siz;
                dp[i][j]=0x3f3f3f3f;
                for(int k=i+1;k<j;k++){
                    dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k][j]+(a[j]-a[i]-2));
                }
            }
        }
        printf("Case #%d: %d\n",ii,dp[0][q+1]);
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


