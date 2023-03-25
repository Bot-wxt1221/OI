#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
int fir[10005];
int nxt[1000005];
int v[1000005];
int aa[1000005];
int bb[1000005];
int cc[1000005];
bool vised[10005];
int now;
int ans=0x3f3f3f3f3f3f3f3fll;
void add(int a,int b,int aaa,int bbb,int ccc){
    now++;
    aa[now]=aaa;
    cc[now]=ccc;
    bb[now]=bbb;
    v[now]=b;
    nxt[now]=fir[a];
    fir[a]=now;
    return ;
}
void dfs(int now,int a,int b,int c){
    if(now==1){
        ans=std::min(ans,a+b+c);
        return ;
    }
    if(ans<=a+b+c){
        return ;
    }
    vised[now]=1;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(!vised[v[i]]){
            dfs(v[i],std::max(aa[i],a),std::max(bb[i],b),std::max(cc[i],c));
        }
    }
    vised[now]=0;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=1;i<=m;i++){
        int a=read();
        int b=read();
        int c=read();
        int d=read();
        int e=read();
        add(b,a,c,d,e);
    }
    dfs(n,0,0,0);
    printf("%lld",ans==0x3f3f3f3f3f3f3f3fll?-1:ans);
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


