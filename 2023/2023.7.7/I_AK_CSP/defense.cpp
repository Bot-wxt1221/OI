#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();
int fir[300005];
int nxt[600005];
int v[600005];
int dp2[300005];
int dp1[300005][2];//have 1 
int p[300005];
int now;
int to[300005][30];
int dep[300005];
int n;
int fa[300005];
int lca(int x,int y){
    int jumpx=x;
    int jumpy=y;
    for(int i=30;i>=1&&fa[jumpx]!=fa[jumpy];i--){
        jumpx=to[x][i];
        jumpy=to[y][i];
        if(jumpx==jumpy){
            continue;
        }
    }
    return fa[jumpx];
}
void add(int x,int y){
    now++;
    v[now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
}

void dfs(int now,int fa){
    dep[now]=dep[fa]+1;
    ::fa[now]=fa;
    dp2[now]=std::min(dp2[fa],dp2[::fa[fa]])+p[now];
    dp1[now][1]+=p[now];
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(fa==v[i]){
            continue;
        }
        dfs(v[i],now);
        dp1[now][0]+=dp1[v[i]][1];
        dp1[now][1]+=std::min(dp1[v[i]][1],dp1[v[i]][0]);
    }
    to[now][0]=now;
    for(int i=1;i<=log2(n)+1;i++){
        to[now][i]=to[to[now][i-1]][i-1];
    }
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	#endif
    n=read();
    int m=read();
    char temp[20];
    scanf("%s",temp);
    for(int i=1;i<=n;i++){
        fir[i]=-1;
        p[i]=read();
    }
    for(int i=1;i<n;i++){
        int x=read();
        int y=read();
        add(x,y);
        add(y,x);
    }
    dfs(1,1);
    for(int i=1;i<=m;i++){
        int a=read();
        int x=read();
        int b=read();
        int y=read();
        int ans=dp1[a][0]+dp1[b][0];
        if(x){
            ans+=dp2[a];
        }else{
            ans+=dp2[fa[a]];
        }
        if(y){
            ans+=dp2[b];
        }else{
            ans+=dp2[fa[b]];
        }
        ans-=dp2[lca(a,b)];
        printf("%d\n",ans);
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


