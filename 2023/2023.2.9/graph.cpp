#include <iostream>
#include <cstdio>
inline int read();
int v[100005];
int w[100005];
int nxt[100005];
int fir[100005];
int now;
void add(int a,int b,int c=1){
    now++;
    v[now]=b;
    w[now]=c;
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
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=1;i<=m;i++){
        int a=read();
        int b=read();
        int c=read();
        add(a,b,c);
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
    邻接表存图
*/


