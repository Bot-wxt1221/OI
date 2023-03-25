#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
inline int read();
class node{
    public:
        int u,v,w;
}a[200005];
bool cmp(node a,node b){
    return a.w<b.w;
}
int fa[5005];
int getfa(int x){
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    int m=read();
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        a[i].u=read();
        a[i].v=read();
        a[i].w=read();
    }
    int sum=0;
    int have=0;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        int fx=getfa(a[i].u);
        int fy=getfa(a[i].v);
        if(fx==fy){
            continue;
        }
        have++;
        sum+=a[i].w;
        fa[fx]=fy;
        if(have==n-1){
            printf("%d",sum);
            return 0;
        }
    }
    printf("orz");
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


