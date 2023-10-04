#include <iostream>
#include <cstdio>
#include <stack>
inline int read();
int fir[10005];
int nxt[10005];
int v[10005];
int out[10005];
bool vised[10005];
class node{
    public:
        int now;
        int v;
        node(int nn,int vv){
            now=nn;
            v=vv;
            return ;
        }
};
std::stack<node>d;
int now;
void add(int a,int b){
    now++;
    v[now]=b;
    nxt[now]=fir[a];
    fir[a]=now;
    return ;
}
void dfs(int step,int now){
    vised[now]=1;
    out[step]=now;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(vised[v[i]]){
            continue ;
        }
        dfs(step+1,v[i]);
    }
    for(int i=1;i<=step;i++){
        printf("%d ",out[i]);
    }
    printf("\n");
    vised[now]=0;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        a=read();
        b=read();
        add(a,b);
    }
    dfs(1,1);
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


