#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*2;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        char opt;
        cin>>opt;
        int p,q;
        cin>>p>>q;
        if(opt=='F'){
            Union(p,q);
            // Union(p+n,q+n);
        }else{
            Union(q+n,p);
            Union(p+n,q);
        }
    }
    int a=0;
    for(int i=1; i<=n; ++i)
		fa[i]=getfa(fa[i]);
	for(int i=1; i<=n; ++i)
		if(fa[i]==i)
			++a;
	printf("%hd",a);
	return 0;
}