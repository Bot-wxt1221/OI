#include <iostream>
#include <cstdio>
inline int read();
int w[10]={0,1,2,3,5,10,20};
int v[10];
bool dp[1005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("weight.in","r",stdin);
	freopen("weight.out","w",stdout);
	#endif
    dp[0]=1;
    for(int i=1;i<=6;i++){
        v[i]=read();
        for(int j=1004;j>=w[i];j--){
            for(int m=1;m<=v[i];m++){
                if(j>=w[i]*m){
                    dp[j]|=dp[j-w[i]*m];
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=1004;i++){
        ans+=dp[i];
    }
    printf("Total=%d",ans);
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

