#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
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
int nxt[50005*2];
int fir[50005*2];
int v[50005*2];
int in[50005*2];
int now=0;
int dp[1505][3];
int k[1505];
void add(int x,int y){
    now++;
    in[y]++;
    v[now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
}
void dfs(int now,int fa){
    dp[now][0]=k[now];
    int d=0x3f3f3f3f;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa){
              continue;
        }
        dfs(v[i],now);
        dp[now][0]+=min(min(dp[v[i]][0],dp[v[i]][1]),dp[v[i]][2]);
        dp[now][1]+=min(dp[v[i]][0],dp[v[i]][1]);
        d=min(d,dp[v[i]][0]-min(dp[v[i]][1],dp[v[i]][0]));
        dp[now][2]+=min(dp[v[i]][0],dp[v[i]][1]);
    }
    dp[now][1]+=d;
    return ;
}
int main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
    int n=read();
   for(int i=1;i<=n;i++){
        fir[i]=-1;
   }
   for(int i=1;i<=n;i++){
    int j=read();
    k[j]=read();
    int m=read();
    for(int i=1;i<=m;i++){
        int temp=read();
        add(j,temp);
        add(temp,j);
    }
   }
        dfs(1,0);
        printf("%d",min(dp[1][0],dp[1][1]));

	return 0;
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

