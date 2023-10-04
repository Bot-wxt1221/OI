#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();
int fir[100005];
int v[200005];
int w[200005];
int nxt[200005];
int now;
int _min[100005][5];
int dis[100005][30];
int depp[100005];
int dis1[100005];
int f1[100005][30];
int f2[100005][30];
void add(int u,int v,int w){
    now++;
    ::v[now]=v;
    ::w[now]=w;
    nxt[now]=fir[u];
    fir[u]=now;
    return ;
}
void update(int now,int to){
    if(_min[now][1]>=to){
        _min[now][3]=_min[now][2];
        _min[now][2]=_min[now][1];
        _min[now][1]=to;
    }else if(_min[now][2]>=to){
        _min[now][3]=_min[now][2];
        _min[now][2]=to;
    }else if(_min[now][3]>=to){
        _min[now][3]=to;
    }
    return ;
}
int getlca(int x,int y){
    if(depp[x]<depp[y]){
        std::swap(x,y);
    }
    while(depp[x]>depp[y]){
        int i=0;
        for(i=29;i>0;i--){
            if(depp[dis[x][i]]>depp[y]){
                break;
            }
        }
        x=dis[x][i];
    }
    while(x!=y){
        int i=0;
        for(i=29;i>0;i--){
            if(dis[x][i]!=dis[y][i]){
                break;
            }
        }
        x=dis[x][i];
        y=dis[y][i];
    }
    return x;
}
void dfs(int now,int fa){
    dis[now][0]=fa;
    for(int i=1;i<30;i++){
        dis[now][i]=dis[dis[now][i-1]][i-1];
    }
    _min[now][1]=0;
    _min[now][2]=_min[now][3]=0xffffffffll;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa){
            continue;
        }
        dis1[v[i]]=dis1[now]+w[i];
        depp[v[i]]=depp[now]+1;
        dfs(v[i],now);
        update(now,_min[v[i]][1]+w[i]);
    }
}
int calc(int &now,int dep,int op,int ex){
    int res=0;
    for(int i=depp[now]-dep;i>0;i-=(i&(-i))){
        int d=std::log2((i)&(-i));
        res=std::min(res,(op?f2[now][d]:f1[now][d])+ex);
        now=dis[now][d];
    }
    return res;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	#endif
    int n=read();
    int q=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    bool to=0;
    for(int i=1;i<n;i++){
        int u=read(),v,w;
        v=read();
        w=read();
        add(u,v,w);
        add(v,u,w);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        int fa=dis[i][0];
        if(!fa){
            continue;
        }
        if(_min[fa][1]==_min[i][1]+dis1[i]-dis1[fa]){
            f1[i][0]=_min[fa][2];
            f2[i][0]=_min[fa][2]-dis1[fa];
        }else{
            f1[i][0]=_min[fa][1];
            f2[i][0]=_min[fa][1]-dis1[fa];
        }
    }
    for(int j=1;j<30;j++){
        for(int i=1;i<=n;i++){
            f1[i][j]=std::min(f1[i][j-1],f1[dis[i][j-1]][j-1]);
            f2[i][j]=std::min(f2[i][j-1],f2[dis[i][j-1]][j-1]);
        }
    }
    for(int i=1;i<=q;i++){
        int x=read(),y=read();
        int lca=getlca(x,y);
        if(depp[x]<depp[y]){
            std::swap(x,y);
        }
        int res=dis1[x]+dis1[y]-2*dis1[lca];
        if(lca==y){
            int t=_min[x][1];
            t=std::min(t,calc(x,depp[lca],0,0));
            t=std::min(t,calc(y,0,1,dis1[lca]));
            res+=t*2;
        }else{
            int t=std::min(_min[x][1],_min[y][1]);
            t=std::min(t,std::min(calc(x,depp[lca]+1,0,0),calc(y,depp[lca]+1,0,0)));
            if(_min[x][1]+dis1[x]>_min[y][1]+dis1[y]){
                std::swap(x,y);
            }
            if(_min[lca][1]==_min[x][1]+dis1[x]-dis1[lca]){
                if(_min[lca][2]==_min[y][1]+dis1[y]-dis1[lca]){
                    t=std::min(t,_min[lca][3]);
                }else{
                    t=std::min(t,_min[lca][2]);
                }
            }else{
                t=std::min(t,_min[lca][1]);
            }
            x=lca;
            t=std::min(t,calc(x,0,1,dis1[lca]));
            res+=t*2;
        }
        printf("%lld\n",res);
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


