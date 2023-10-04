#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define int long long
#define MAX_IN 0x3f3f3f3f3f3f3f3f
inline int read();
int tag[205][205];
int dep[205];
int secfir[205];
int fir[205];
int nxt[10005];
int v[10005];
int flow[10005];//容量
int cap[10005];//流量
int now=1,s,t;
std::queue<int>a;
void add(int x,int y,int z){
    if(tag[x][y]){
        flow[tag[x][y]]+=z;
        return ;
    }
    now++;
    tag[x][y]=now;
    v[now]=y;
    flow[now]=z;
    nxt[now]=fir[x];
    cap[now]=0;
    fir[x]=now;
    return ;
}
bool bfs(){
    memset(dep,0,sizeof(dep));
    a.push(s);
    dep[s]=1;
    while(a.size()>0){
        int x=a.front();
        a.pop();
        for(int i=fir[x];i!=-1;i=nxt[i]){
            if(flow[i]-cap[i]>0&&dep[v[i]]==0){
                a.push(v[i]);
                dep[v[i]]=dep[x]+1;
            }
        }
    }
    return dep[t]!=0;
}
int dfs(int now,int flow){
    if(now==t){
        return flow;
    }
    if(flow==0){
        return 0;
    }
    int res=0;
    for(int &i=secfir[now];i!=-1;i=nxt[i]){
        if(::flow[i]-cap[i]>0&&dep[now]+1==dep[v[i]]){
            int k=dfs(v[i],std::min(flow-res,::flow[i]-cap[i]));
            if(k==0){
                dep[v[i]]=-1;
            }
            cap[i]+=k;
            cap[i^1]-=k;
            res+=k;
            if(flow==res){
                return res;
            }
        }
    }
    return res;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    s=read();
    t=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=1;i<=m;i++){
        int u=read(),v,w;
        v=read();
        w=read();
        add(u,v,w);
        add(v,u,0);
    }
    int ans=0;
    while(bfs()!=0){
        memcpy(secfir,fir,sizeof(fir));
        ans+=dfs(s,MAX_IN);
    }
    printf("%lld",ans);
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


