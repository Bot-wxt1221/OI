#include <iostream>
#include <cstdio>
#define int long long
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
int fa[500005];
int getfa(int x){
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n=read();
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int ans=0;
    for(int i=n/2;i>=1;i--){
        for(int j=2;j*i<=n;j++){
            if(getfa(i)!=getfa(i*j)){
                fa[getfa(i*j)]=fa[i];
                ans+=i;
            }
        }
    }
    printf("%lld %lld",ans,n-1);
	return 0;
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


