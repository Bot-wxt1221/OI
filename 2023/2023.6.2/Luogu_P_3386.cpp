#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define int long long
#define MAX_IN 0x3f3f3f3f3f3f3f3f
inline int read();
int tag[1005][1005];
int dep[1005];
int secfir[1005];
int fir[1005];
int nxt[200005];
int v[200005];
int flow[200005];//容量
int cap[200005];//流量
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
    int n1=read(),m1,e1;
    m1=read();
    e1=read();
    int n=n1+m1+1;
    t=n1+m1+1;
    s=0;
    for(int i=0;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=1;i<=n1;i++){
        add(0,i,1);
        add(i,0,0);
    }
    for(int i=n1+1;i<=m1+n1;i++){
        add(i,t,1);
        add(t,i,0);
    }
    for(int i=1;i<=e1;i++){
        int u=read(),v;
        v=read();
        add(u,v+n1,1);
        add(v+n1,u,0);
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


