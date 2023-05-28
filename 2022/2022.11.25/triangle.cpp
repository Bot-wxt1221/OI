#include <iostream>
#include <cstdio>
inline int read();
class node{
    public:
        int ans,to;
        node(int aans=0,int tto=0){
            ans=aans;
            to=tto;
        }
};
int a[1005][1005];
node dp[1005][1005];
int dpp[1005];
int n;
void dfs(int i,int j);
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            a[i][j]=read();
            if(i==n){
                dp[i][j]=node(a[i][j],0);
            }
        }
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(dp[i+1][j].ans>dp[i+1][j+1].ans){
                dp[i][j].ans=dp[i+1][j].ans+a[i][j];
                dp[i][j].to=1;
            }else if(dp[i+1][j].ans==dp[i+1][j+1].ans){
                dp[i][j].ans=dp[i+1][j].ans+a[i][j];
                dp[i][j].to=3;
            }
            else {
                dp[i][j].ans=dp[i+1][j+1].ans+a[i][j];
                dp[i][j].to=2;
            }
        }
    }
    printf("%d\n",dp[1][1].ans);
    dfs(1,1);
	return 0;
}
void dfs(int i,int j){
    dpp[i]=j;
    if(i==n){
        for(int i=1;i<=n;i++){
            printf("%d %d\n",i,dpp[i]);
        }
        printf("\n");
        return ;
    }
    if(dp[i][j].to==1){
        dfs(i+1,j);
    }
    if(dp[i][j].to==2){
        dfs(i+1,j+1);
    }
    if(dp[i][j].to==3){
        dfs(i+1,j);
        dfs(i+1,j+1);
    }
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
    数字金字塔，输出路径
Example:
	1:
		In:
            5
            8
            12 15
            3 9 6
            8 10 5 12
            16 4 18 10 9
		Out:
            60
            1 1
            2 2
            3 2
            4 2
            5 3
    2:
        In:
            5
            8
            12 15
            3 9 6
            8 10 5 12
            100 4 18 10 9
        Out:
            131
            1 1
            2 1
            3 1
            4 1
            5 1
    3:
        In:
            5
            8
            1 1
            4 5 1
            4 1 9 1
            9 8 1 0 114514
        Out:
            114525
            1 1
            2 2
            3 3
            4 4
            5 5
    4:
        In:
            5
            8
            12 15
            3 9 6
            8 10 5 12
            16 4 18 19 9
        Out:
            60
            1 1
            2 2
            3 2
            4 2
            5 3

            1 1
            2 2
            3 3
            4 4
            5 4
More:
    两种状态定义，不同枚举顺序，不同转移方程
*/


