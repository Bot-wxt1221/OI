#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
bool vised[10005];
class graph{
    public:
        int fir[10005];
        int nxt[10005];
        int v[10005];
        int w[10005];
        int now;
        graph(int n=0){
            now=0;
            for(int i=1;i<=n;i++){
                fir[i]=-1;
            }
        }
        void add(int a,int b,int c){
            now++;
            w[now]=c;
            v[now]=b;
            nxt[now]=fir[a];
            fir[a]=now;
            return ;
        }
}g,t;
class node{
    public:
        int now,dis;
        int u;
        node(int nn=0,int dd=0,int uu=0){
            now=nn;
            dis=dd;
            u=uu;
        }
};
bool operator < (node a,node b){
    return a.dis>b.dis;
}
std::priority_queue<node>qu;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("mst_I.in","r",stdin);
	freopen("mst_I.out","w",stdout);
	#endif
    int n=read();
    g=graph(n);
    t=graph(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a=read();
            if(a!=-1){
                g.add(i,j,a);
            }
        }
    }
    vised[1]=1;
    for(int i=g.fir[1];i!=-1;i=g.nxt[i]){
        qu.push(node(g.v[i],g.w[i],1));
    }
    int ans=0;
    while(qu.size()>0){
        node temp=qu.top();
        qu.pop();
        if(vised[temp.now]){
            continue;
        }
        vised[temp.now]=1;
        t.add(temp.u,temp.now,temp.dis);
        ans+=temp.dis;
        for(int i=g.fir[temp.now];i!=-1;i=g.nxt[i]){
            qu.push(node(g.v[i],g.w[i],temp.now));
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


