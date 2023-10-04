#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int fa[200005];
int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
class edge{
    public:
        int u,v,w;
}g[200005];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int v[200006];
int w[200006];
int fir[200005];
int nxt[200005];
int now;
void add(int a,int b,int c){
    v[++now]=b;
    w[now]=c;
    nxt[now]=fir[a];
    fir[a]=now;
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("mst_II.in","r",stdin);
	freopen("mst_II.out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    for(int i=0;i<n;i++){
        fa[i]=i;
        fir[i]=-1;
    }
    for(int i=1;i<=m;i++){
        g[i].u=read();
        g[i].v=read();
        g[i].w=read();
    }
    int ans=0;
    std::sort(g+1,g+m+1,cmp);
    for(int i=1;i<=m;i++){
        int fx=getfa(g[i].u);
        int fy=getfa(g[i].v);
        if(fx!=fy){
            add(g[i].u,g[i].v,g[i].w);
            ans+=g[i].w;
            fa[fx]=fy;
        }
    }
    printf("%d",ans);
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


