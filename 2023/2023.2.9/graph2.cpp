#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
std::vector <int > g[100005];
int u[100005];
int v[100005];
int now;
void add(int a,int b,int c){
    now++;
    u[now]=b;
    v[now]=c;
    g[a].push_back(now);
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
    std::vector存图
*/


