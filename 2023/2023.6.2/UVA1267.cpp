#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
inline int read();
int fir[10005];
int nxt[20005];
int leng[10005],k,s;
int v[20005];
int now;
void add(int x,int y){
    now++;
    v[now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
}
int gok[10005];
int fa[10005];
int depth[10005];
bool color[10005];
std::vector<int>a[10005];
int m_dep=0;
int have=0;
void dfs(int now,int fa){
    ::fa[now]=fa;
    depth[now]=depth[fa]+1;
    m_dep=std::max(m_dep,depth[now]);
    leng[depth[now]]=now;
    int cnt=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa){
            continue;
        }
        cnt++;
        dfs(v[i],now);
    }
    if(cnt==0){
        have--;
        if(depth[now]>k+1){
            have++;
            gok[now]=leng[depth[now]-k];
            a[depth[now]].push_back(now);
        }
    }
    return ;
}
void dfs2(int now,int dep,int fa){
    if(dep>k){
        return ;
    }
    color[now]=1;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa){
            continue;
        }
        dfs2(v[i],dep+1,now);
    }
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n;
    int t=read();
    while(scanf("%d%d",&n,&s)!=EOF){
        memset(color,0,sizeof(color));
        memset(depth,0,sizeof(depth));
        m_dep=0;
        have=0;
        k=read();
        for(int i=1;i<=n;i++){
            fir[i]=-1;
            a[i].clear();
        }
        for(int i=1;i<n;i++){
            int u=read(),v;
            v=read();
            add(u,v);
            add(v,u);
        }
        dfs(s,s);
        dfs2(s,0,s);
        int ans=0;
        for(int i=m_dep;i>=1;i--){
            for(int j=0;j<a[i].size();j++){
                if(color[a[i][j]]){
                    continue;
                }
                ans++;
                dfs2(gok[a[i][j]],0,gok[a[i][j]]);
            }
        }
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


