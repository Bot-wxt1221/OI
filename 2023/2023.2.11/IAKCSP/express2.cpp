#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int fir[1005];
int nxt[1000005];
int v[1000005];
int w[1000005];
bool vised[1005];
int now=0;
int dis[1005];
void add(int a,int b,int c){
    now++;
    w[now]=c;
    v[now]=b;
    nxt[now]=fir[a];
    fir[a]=now;
    return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("express.in","r",stdin);
	freopen("express.out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
        dis[i]=0x3f3f3f3f;
    }
    for(int i=1;i<=m;i++){
        int a=read();
        int b=read();
        int c=read();
        add(a,b,c);
        add(b,a,c);
    }
    int ans=1;
    dis[1]=0;
    vised[1]=1;
    for(int i=fir[1];i!=-1;i=nxt[i]){
        dis[v[i]]=w[i];
    }
    int anss=0;
    while(ans<n){
        int _min=0x3f3f3f3f,mini;
        for(int i=1;i<=n;i++){
            if(_min>dis[i]&&vised[i]==0){
                _min=dis[i];
                mini=i;
            }
        }
        ans++;
        vised[mini]=1;
        anss+=_min;
        for(int i=fir[mini];i!=-1;i=nxt[i]){
            dis[v[i]]=std::min(dis[v[i]],w[i]);
        }
    }
    printf("%lld",anss);
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

