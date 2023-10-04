#include <iostream>
#include <cstdio>
inline int read();
int v[505],w[505],s[505];
int dp[6005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	#endif
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        v[i]=read();
        w[i]=read();
        s[i]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int si=1;si<=s[i];si++){
                if(j>=v[i]*si){
                    dp[j]=std::max(dp[j],dp[j-v[i]*si]+w[i]*si);
                }
            }
        }
    }
    printf("%d",dp[m]);
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

