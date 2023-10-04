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
	freopen("disjoint_set.in","r",stdin);
	freopen("disjoint_set.out","w",stdout);
	#endif
    int n=read();
    int q=read();
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=q;i++){
        int k=read();
        int x=read();
        int y=read();
        if(k==0){
            fa[getfa(x)]=getfa(y);
        }else{
            printf("%d\n",getfa(x)==getfa(y));
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


