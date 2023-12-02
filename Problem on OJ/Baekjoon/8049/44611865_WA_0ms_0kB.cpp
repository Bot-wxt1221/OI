#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#define int long long
#define mod1 1000000003
#define mod2 100000000007
inline int read();
int in[500005];
int to[500005][4];
int now,n;
char a[500005];
int hs1[500005];
int hs2[500005];
std::queue<int>qu;
bool vised[500005];
void dfs(int now){
    if(vised[now]){
        return ;
    }
    vised[now]=1;
    if(now==n){
        return ;
    }
    hs1[now]=hs2[now]=mod1+mod2+1912121+114514810;
    vised[now]=1;
    for(int i=1;i<=3;i++){
        dfs(to[now][i]);
        hs1[now]+=a[now]*mod2-'A'+2;
        // hs1[now]%=mod1;
        hs1[now]+=hs1[to[now][i]]+1144110+111+mod2;
        // hs1[now]%=mod1;
        hs1[now]+=(i*1919);
        // hs1[now]%=mod1;
        hs2[now]+=a[now]*mod2-'A'*mod2+12123;
        // hs2[now]%=mod2;
        hs2[now]+=hs2[to[now][i]]*192*mod1+1145141919810;
        // hs2[now]%=mod2;
        hs2[now]+=(i*114512113*mod1);
        // hs2[now]%=mod2;
    }
    return ;
}
std::map<int,int>ma1;
// std::map<int,int>ma2;
bool vised2[500005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    n=read();
    for(int i=1;i<n;i++){
        int ci=3;
        while('A'>(a[i]=getchar())||a[i]>'Z');
        for(int j=1;j<=ci;j++){
            to[i][j]=read();
        }
    }
    dfs(1);
    qu.push(1);
    int lsd=0;
    int ans=1;
    vised[1]=1;
    while(qu.size()>0){
        int now=qu.front();
        qu.pop();
        if(now==n){
            continue;
        }
        for(int i=1;i<=3;i++){
            if(vised2[to[now][i]]){
                continue;
            }
            vised2[to[now][i]]=1;
            if(ma1[hs1[to[now][i]]+hs2[to[now][i]]]==0){
                ma1[hs1[to[now][i]]+hs2[to[now][i]]]=1;
                ans++;
            }
            qu.push(to[now][i]);
        }
    }
    printf("%lld",ans);
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


