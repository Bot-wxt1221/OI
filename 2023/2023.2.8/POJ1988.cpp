#include <iostream>
#include <cstdio>
inline int read();
int fa[30005];
int siz[30005];
int d[30005];
int getfa(int x){
    if(fa[x]==x){
        return x;
    }
    int root=getfa(fa[x]);
    d[x]+=d[fa[x]];
    fa[x]=root;
    return fa[x];
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    for(int i=1;i<=30000;i++){
        fa[i]=i;
        siz[i]=1;
    }
    int p=read();
    for(int i=1;i<=p;i++){
        char temp[100];
        scanf("%s",temp);
        if(temp[0]=='M'){
            int a=getfa(read());
            int b=getfa(read());
            if(a==b){
                continue;
            }
            fa[b]=a;
            d[b]=siz[a];
            siz[a]+=siz[b];
        }else{
            int x=read();
            int fx=getfa(x);
            printf("%d\n",siz[fx]-d[x]-1);
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

