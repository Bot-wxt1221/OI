#include <iostream>
#include <cstdio>
inline int read();
int fa[200005];
int getfa(int n){
    return fa[n]==n?n:fa[n]=getfa(fa[n]);
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	#endif
    int T=read();
    while(T--){
        int n,m;
        n=read();
        m=read();
        for(int i=1;i<=2*n;i++){
            fa[i]=i;
        }
        for(int i=1;i<=m;i++){
            char temp[100];
            scanf("%s",&temp);
            if(temp[0]=='A'){
                int x,y;
                x=read();
                y=read();
                int fx=getfa(x);
                int fx2=getfa(x+n);
                int fy=getfa(y);
                int fy2=getfa(y+n);
                if(fx==fy){
                    printf("In the same gang.\n");
                }else if(fx==fy2){
                    printf("In different gangs.\n");
                }else{
                    printf("Not sure yet.\n");
                }
            }else{
                int x=read();
                int y=read();
                int fx=getfa(x);
                int fx2=getfa(x+n);
                int fy=getfa(y);
                int fy2=getfa(y+n);
                fa[fy2]=fx;
                fa[fx2]=fy;
            }
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
