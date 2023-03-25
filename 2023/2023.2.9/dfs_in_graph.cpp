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
    d.push(node(1,0));
    int anow=0;
    while(d.size()>0){
        node now=d.top();
        d.pop();
        if(now.v==0){
            if(vised[now.now]){
                continue;
            }
            vised[now.now]=1;
            out[++anow]=now.now;
            d.push(node(now.now,fir[now.now]));
        }else if(now.v!=-1){
            d.push(node(now.now,nxt[now.v]));
            d.push(node(v[now.v],0));
        }else{
            for(int i=1;i<=anow;i++){
                printf("%d ",out[i]);
            }
            printf("\n");
            vised[now.now]=0;
            --anow;
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


