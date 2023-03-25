#include <iostream>
#include <cstdio>
inline int read();
int a[1005][1005];
bool dp[1005][1005][20];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read();
    int _max=0,qian_max;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            a[i][j]=read();
            a[i][j]%=10;
            if(i==n){
                dp[i][j][a[i][j]]=1;
            }
        }
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            for(int m=0;m<10;m++){
                dp[i][j][m]|=dp[i+1][j][(m-a[i][j]+10)%10];
                dp[i][j][m]|=dp[i+1][j+1][(m-a[i][j]+10)%10];
            }
        }
    }
    for(int i=9;i>=0;i--){
        if(dp[1][1][i]){
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
    数字金字塔，使得路径数值和个位数尽量大
Example:
	1:
		In:
            5
            8
            12 15
            3 9 6
            8 10 5 12
            100 4 18 10 9
		Out:
            7
    2:
        In:
            5
            8
            12 15
            3 9 6
            8 10 5 12
            16 4 18 10 9
        Out:
            7
    3:
        In:
            5
            8
            1 1
            4 5 1
            4 1 9 1
            9 8 1 0 114514
        Out:
            9
    4:
        In:
            5
            8
            12 15
            3 9 6
            8 10 5 12
            16 4 18 19 9
        Out:
            7
More:
    定义状态个位是否能够是这么多
*/


