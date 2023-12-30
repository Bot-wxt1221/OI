#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int n,m;
int ques[105];
int res[105];
namespace New{
    int fir[200005];
    int nxt[400005];
    int v[400005];
    int w[400005];
    int u[400005];
    int now;
    int siz[200005];
    bool vised[200005];
    int newnode;
    void add(int u,int v,int w){
        New::u[++now]=u;
        New::v[now]=v;
        New::w[now]=w;
        nxt[now]=fir[u];
        fir[u]=now;
        return ;
    }
    int cnt=0;
    int cho=0;
    int minn=0x3f3f3f3f;
    void calcsiz(int now,int fa){
        siz[now]=1;
        for(int i=fir[now];i!=-1;i=nxt[i]){
            if(v[i]==fa||vised[v[i]]){
                continue;
            }
            calcsiz(v[i],now);
            siz[now]+=siz[v[i]];
            if(std::abs(cnt-siz[v[i]]-siz[v[i]])<minn){
                minn=std::abs(cnt-siz[v[i]]-siz[v[i]]);
                cho=i;
            }
        }
        return ;
    }
    int dfn=0;
    int dd[200005];
    int dis[200005];
    void calcdis(int now,int fa){
        dd[++dfn]=dis[now];
        for(int i=fir[now];i!=-1;i=nxt[i]){
            if(v[i]==fa||vised[v[i]]){
                continue;
            }
            dis[v[i]]=dis[now]+w[i];
            calcdis(v[i],now);
        }
    }
    std::queue<int >clr;
    bool df[10000005];
    void dfs(int now,int fa){
        cnt=siz[now];
        minn=0x3f3f3f3f;
        calcsiz(now,fa);
        int choo=cho;
        df[0]=1;
        clr.push(0);
        vised[now]=1;
        bool yes=0;
        
        if(fa==v[choo]||vised[v[choo]]){
            goto loop;
        }
        yes=1;
        dis[v[choo]]=0;
        dfn=0;
        calcdis(v[choo],u[choo]);
        for(int j=1;j<=dfn;j++){
            for(int kk=1;kk<=m;kk++){
                if(ques[kk]>=dd[j]+w[choo]){
                    res[kk]|=df[ques[kk]-dd[j]-w[choo]];
                }
            }
        }
        for(int j=1;j<=dfn;j++){
            if(dd[j]<=10000001){
                df[dd[j]]=1;
                clr.push(dd[j]);
            }
        }
        loop:{}
        if(fa==u[choo]||vised[u[choo]]){
            goto loop2;
        }
        yes=1;
        dis[u[choo]]=0;
        dfn=0;
        calcdis(u[choo],v[choo]);
        for(int j=1;j<=dfn;j++){
            for(int kk=1;kk<=m;kk++){
                if(ques[kk]>=dd[j]+w[choo]){
                    res[kk]|=df[ques[kk]-dd[j]-w[choo]];
                }
            }
        }
        for(int j=1;j<=dfn;j++){
            if(dd[j]<=10000001){
                df[dd[j]]=1;
                clr.push(dd[j]);
            }
        }
        loop2:{}
        while(clr.size()>0){
            df[clr.front()]=0;
            clr.pop();
        }
        if(!yes){
            return ;
        }
        calcsiz(u[choo],v[choo]);
        calcsiz(v[choo],u[choo]);
        dfs(u[choo],v[choo]);
        dfs(v[choo],u[choo]);
    }
};

namespace old{
    int fir[100005];
    int nxt[200005];
    int v[200005];
    int w[200005];
    int now;
    void add(int u,int v,int w){
        old::v[++now]=v;
        old::w[now]=w;
        nxt[now]=fir[u];
        fir[u]=now;
        return ;
    }
    void dfs(int now,int fa){
        int last=now;
        bool to=0;
        int uu,vv;
        for(int i=fir[now];i!=-1;i=nxt[i]){
            if(v[i]==fa){
                continue;
            }
            if(to){
                New::add(uu,vv,0);
            }
            New::add(last,v[i],w[i]);
            New::newnode++;
            to=1;
            uu=last;
            vv=New::newnode;
            last=New::newnode;
            dfs(v[i],now);
        }
        New::newnode-=to;
    }
};

int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    n=read();
    m=read();
    New::newnode=n;
    for(int i=1;i<=n;i++){
        old::fir[i]=-1;
        New::fir[i]=New::fir[i+n]=-1;
    }
    for(int i=1;i<n;i++){
        int u=read();
        int v=read();
        int w=read();
        old::add(u,v,w);
        old::add(v,u,w);
    }
    for(int i=1;i<=m;i++){
        ques[i]=read();
    }
    New::df[0]=1;
    New::clr.push(0);
    New::minn=0x3f3f3f3f;
    old::dfs(1,1);
    New::cnt=New::newnode;
    New::calcsiz(1,-1);
    int choo=New::cho;
    New::dfn=0;
    New::dis[New::u[choo]]=0;
    New::calcdis(New::u[choo],New::v[choo]);
    for(int j=1;j<=New::dfn;j++){
        for(int kk=1;kk<=m;kk++){
            if(ques[kk]>=New::dd[j]+New::w[choo]){
                res[kk]|=New::df[ques[kk]-New::dd[j]-New::w[choo]];
            }
        }
    }
    for(int j=1;j<=New::dfn;j++){
        if(New::dd[j]<=10000001){
            New::df[New::dd[j]]=1;
            New::clr.push(New::dd[j]);
        }
    }
    New::dfn=0;
    New::dis[New::v[choo]]=0;
    New::calcdis(New::v[choo],New::u[choo]);
    for(int j=1;j<=New::dfn;j++){
        for(int kk=1;kk<=m;kk++){
            if(ques[kk]>=New::dd[j]+New::w[choo]){
                res[kk]|=New::df[ques[kk]-New::dd[j]-New::w[choo]];
            }
        }
    }
    for(int j=1;j<=New::dfn;j++){
        if(New::dd[j]<=10000001){
            New::df[New::dd[j]]=1;
            New::clr.push(New::dd[j]);
        }
    }
    while(New::clr.size()>0){
        New::df[New::clr.front()]=0;
        New::clr.pop();
    }
    New::calcsiz(New::u[choo],New::v[choo]);
    New::calcsiz(New::v[choo],New::u[choo]);
    New::dfs(New::u[choo],New::v[choo]);
    New::dfs(New::v[choo],New::u[choo]);
    for(int i=1;i<=m;i++){
        if(res[i]){
            printf("AYE\n");
        }else{
            printf("NAY\n");
        }
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


