#include <iostream>
#include <cstdio>
inline int read();
int fir[20005];
int nxt[40005];
int v[40005];
int now;
void add(int x,int y){
    now++;
    v[now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
}
int siz[20005];
int we[20005];
int he[5];
int num=0,n;
void dfs(int now,int fa){
    siz[now]=1;
    we[now]=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa){
            continue;
        }
        dfs(v[i],now);
        siz[now]+=siz[v[i]];
        we[now]=std::max(we[now],siz[v[i]]);
    }
    we[now]=std::max(we[now],n-siz[now]);
    if(we[now]<=n/2){
        he[++num]=now;
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
    while(T--){
        n=read();
        now=0;
        for(int i=1;i<=n;i++){
            fir[i]=-1;
        }
        for(int i=1;i<n;i++){
            int u=read(),v;
            v=read();
            add(u,v);
            add(v,u);
        }
        num=0;
        dfs(1,1);
        int ans=he[1];
        for(int i=2;i<=num;i++){
            if(he[i]<ans){
                ans=he[i];
            }
        }
        printf("%d %d\n",ans,we[ans]);
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


