#include <iostream>
#include <cstdio>
inline int read();
int fir[1006];
int nxt[10005];
int u[10005];
int v[10005];
int w[10005];
int dis[1005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("layout.in","r",stdin);
	freopen("layout.out","w",stdout);
	#endif
    int n=read(),k,l;
    k=read();
    l=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
        dis[i]=0x3f3f3f3f;
    }
    for(int i=1;i<=k;i++){
        int a=read();
        int b=read();
        if(a>b){
            std::swap(a,b);
        }
        u[i]=a;
        v[i]=b;
        w[i]=read();
    }
    for(int i=1;i<=l;i++){
        int a=read();
        int b=read();
        if(a<b){
            std::swap(a,b);
        }
        u[i+k]=a;
        v[i+k]=b;
        w[i+k]=-read();
    }
    dis[1]=0;
    for(int i=1;i<n;i++){
        bool flag=0;
        for(int i=1;i<=l+k;i++){
            if(dis[v[i]]>dis[u[i]]+w[i]){
                dis[v[i]]=dis[u[i]]+w[i];
                flag=1;
            }
        }
        if(!flag){
            break;
        }
    }
    bool flag=0;
    for(int i=1;i<=l+k;i++){
        if(dis[v[i]]>dis[u[i]]+w[i]){
            dis[v[i]]=dis[u[i]]+w[i];
            flag=1;
        }
    }
    if(flag){
        printf("-1");
        return 0;
    }
    if(dis[n]==0x3f3f3f3f){
        printf("-2");
    }else if(dis[n]<0){
        printf("-1");
    }else{
        printf("%d",dis[n]);
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


