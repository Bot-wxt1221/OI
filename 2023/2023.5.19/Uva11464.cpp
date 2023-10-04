#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int map1[20][20];
int map2[20][20];
int ans=0,n;
int ans2=0;
int solve(){//按已枚举出的第一行推出下面的方案
    int temp=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){//map2仅限于此范围修改，不对其他作任何影响
            map2[i][j]=map1[i-1][j]+map1[i][j-1]+map1[i][j+1]+map1[i+1][j];//此行会访问到map1[n+1]，有一定风险，清零即可
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map2[i-1][j]%2){
                if(map1[i][j]==1){//压根动不了，方案不行
                    return 0x3f3f3f3f;
                }
                map2[i-1][j]++;
                map2[i+1][j]++;
                map2[i][j+1]++;
                temp++;
                map2[i][j-1]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(map2[n][i]%2){//不要漏掉
            return 0x3f3f3f3f;
        }
    }
    return temp;
}
void dfs(int step,int maxn){
    if(step==maxn+1){
        ans=std::min(ans,ans2+solve());//ans处理最小答案，ans2处理第一行
        return ;
    }
    dfs(step+1,maxn);
    if(map1[1][step]==0){
        map1[1][step]=1;
        ans2++;
        dfs(step+1,maxn);
        ans2--;//一定要清0啊qwq
        map1[1][step]=0;
    }
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int T=read();
    for(int TT=1;TT<=T;TT++){
        ans=0x3f3f3f3f;//初始化qwq
        n=read();
        memset(map1,0,sizeof(map1));
        memset(map2,0,sizeof(map2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                map1[i][j]=read();
            }
        }
        dfs(1,n);
        if(ans==0x3f3f3f3f){
            ans=-1;
        }
        printf("Case %d: %d\n",TT,ans);
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
    Exercise
Description:
    将一个01矩阵中的若干0变成1，使得每个数上下左右数的和都是偶数，最少改变多少个0
Example:
	1:
		In:
            3
            3
            0 0 0
            0 0 0
            0 0 0
            3
            0 0 0
            1 0 0
            0 0 0
            3
            1 1 1
            1 1 1
            0 0 0
		Out:
            Case 1: 0
            Case 2: 3
            Case 3: -1
More:
    枚举第一行后直接向后推
*/