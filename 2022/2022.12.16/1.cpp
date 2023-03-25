#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int u[105],v[105];
int dp[10005];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read(),w=read();
    for(int i=1;i<=n;i++){
        u[i]=read();
        v[i]=read();
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=10000;j>=v[i];j--){
            dp[j]=std::min(dp[j],dp[j-v[i]]+u[i]);
        }
    }
    for(int i=10000;i>=1;i--){
        if(dp[i]<=w){
            printf("%d",i);
            return 0;
        }
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
    Example
Description:
    从 i个物品中选取总重量不超过 W的物品，价值最大
Example:
	1:
		In:
            5 10
            2 4
            5 2
            2 4
            2 4
            5 3
		Out:
            12
    2:
        In:
            3 70
            71 100
            69 1
            1 2
        Out:
            3
    3:
        In:
            4 5
            2 3
            1 2
            3 4
            2 2
        Out:
            7
More:
    dp[j]表示 j价值重量最小值
*/

