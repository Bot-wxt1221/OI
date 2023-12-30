#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int n,m;
int ques[105];
int nummmm;
int res[105];
class node{
    public:
        int num;
        bool df[10000005];
        int seq[200005];
        node(){
            num=0;
        }
};
namespace New{
    int fir[200005];
    int nxt[400005];
    int v[400005];
    int w[400005];
    int u[400005];
    int now=1;
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

    void cal(int now,int fa,int d,node *a){
        if(d>=10000001){
            return ;
        }
        (*a).df[d]=1;
        (*a).seq[++(*a).num]=d;
        for(int i=fir[now];i!=-1;i=nxt[i]){
            if(vised[i]||fa==v[i]){
                continue;
            }
            cal(v[i],now,d+w[i],a);
        }
        return ;
    }
    void clr(int now,int fa,int d,node *a){
        if(d>=10000001){
            return ;
        }
        (*a).df[d]=0;
        --(*a).num;
        for(int i=fir[now];i!=-1;i=nxt[i]){
            if(vised[i]||fa==v[i]){
                continue;
            }
            clr(v[i],now,d+w[i],a);
        }
    }
    int minn,cho,cnt;
    void csiz(int now,int fa){
        siz[now]=1;
        for(int i=fir[now];i!=-1;i=nxt[i]){
            if(vised[i]||fa==v[i]){
                continue;
            }
            csiz(v[i],now);
            siz[now]+=siz[v[i]];
            if(std::max(siz[v[i]],cnt-siz[v[i]])<minn){
                minn=std::max(siz[v[i]],cnt-siz[v[i]]);
                cho=i;
            }
        }
        return ;
    }
    node aa,bb;
    void dfs(int i){
        vised[i]=vised[i^1]=1;
        nummmm++;
        cal(u[i],v[i],0,&aa);
        cal(v[i],u[i],w[i],&bb);
        for(int ii=1;ii<=(aa).num;ii++){
            for(int j=1;j<=m;j++){
                if(ques[j]>=aa.seq[ii]){
                    res[j]|=bb.df[ques[j]-aa.seq[ii]];
                }
            }
        }
        clr(u[i],v[i],0,&aa);
        clr(v[i],u[i],w[i],&bb);
        csiz(u[i],v[i]);
        if(siz[u[i]]>1){
            minn=0x3f3f3f3f;
            cnt=siz[u[i]];
            csiz(u[i],v[i]);
            dfs(cho);
        }
        csiz(v[i],u[i]);
        if(siz[v[i]]>1){
            minn=0x3f3f3f3f;
            cnt=siz[v[i]];
            csiz(v[i],u[i]);
            dfs(cho);
        }
        return ;
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
                New::add(vv,uu,0);
                // std::cerr<<uu<<' '<<vv<<std::endl;
            }
            New::add(last,v[i],w[i]);
            New::add(v[i],last,w[i]);
            // std::cerr<<last<<' '<<v[i]<<std::endl;
            New::newnode++;
            to=1;
            uu=last;
            vv=New::newnode;
            last=New::newnode;
            dfs(v[i],now);
        }
        // New::newnode-=to;
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
    for(int i=1;i<=old::now;i++){
        for(int j=1;j<=m;j++){
            if(old::w[i]==ques[j]){
                res[j]=1;
            }
        }
    }
    old::dfs(1,1);
    New::csiz(1,1);
    New::cnt=New::siz[1];
    New::minn=0x3f3f3f3f;
    New::csiz(1,1);
    New::dfs(New::cho);
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

