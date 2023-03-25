#include <iostream>
#include <cstdio>
inline int read();
int a[1005][1005];
int dp[1005][1005][2];
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
            if(i==n){
                dp[i][j][0]=a[i][j];
                _max=std::max(dp[i][j][0],_max);
            }
        }
    }
    for(int i=n-1;i>=1;i--){
        qian_max=_max;
        _max=0;
        for(int j=1;j<=i;j++){
            dp[i][j][0]=std::max(dp[i+1][j][0],dp[i+1][j+1][0])+a[i][j];
            _max=std::max(dp[i][j][0],_max);
            dp[i][j][1]=std::max(dp[i+1][j][1],dp[i+1][j+1][1])+a[i][j];
            dp[i][j][1]=std::max(dp[i][j][1],qian_max+a[i][j]);
        }
    }
    printf("%d",std::max(dp[1][1][1],dp[1][1][0]));
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
    数字金字塔，可以一次跳到下一行任意位置
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
            142
    2:
        In:
            5
            8
            12 15
            3 9 6
            8 10 5 12
            16 4 18 10 9
        Out:
            60
    3:
        In:
            5
            8
            1 1
            4 5 1
            4 1 9 1
            9 8 1 0 114514
        Out:
            114537
    4:
        In:
            5
            8
            12 15
            3 9 6
            8 10 5 12
            16 4 18 19 9
        Out:
            63
More:
    定义状态是否使用此次机会
*/


