#include <iostream>
#include <cstdio>
inline int read();
int fa[100005];
int getfa(int n){
    return fa[n]==n?n:fa[n]=getfa(fa[n]);
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("connect.in","r",stdin);
	freopen("connect.out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        fa[getfa(read())]=fa[getfa(read())];
    }
    int q=read();
    for(int i=1;i<=q;i++){
        if(getfa(read())==getfa(read())){
            printf("yes\n");
        }else{
            printf("no\n");
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


