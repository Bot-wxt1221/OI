#include <iostream>
#include <cstdio>
inline int read();
int fa[10005];
int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("gangs.in","r",stdin);
	freopen("gangs.out","w",stdout);
	#endif
    int n,m;
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a=read();
        int b=read();
        fa[getfa(a)]=getfa(b);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(fa[i]==i){
            ans++;
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


