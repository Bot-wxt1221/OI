#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
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
int fa[2005];
bool have[2006];
int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void Union(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x!=y)
       fa[x]=y;
    return ;
}
signed main(){
    // freopen("in.in","r",stdin);
    // freopen("out.out","w",stdout);
    int n=read();
    int m=read();
    for(int i=1;i<=n*2;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        char opt;
        scanf("%c",&opt);
        int p=read();
        int q=read();
        if(opt=='F'){
            Union(p,q);
            // Union(p+n,q+n);
        }else{
            Union(q+n,p);
            Union(p+n,q);
        }
    }
    int count[2001]={0};
    for(int i=1;i<=n;i++)
        count[getfa(i)]++;
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(count[i]) cnt++;
    printf("%d",cnt);
	return 0;
}