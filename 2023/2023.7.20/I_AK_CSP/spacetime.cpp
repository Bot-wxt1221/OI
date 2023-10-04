#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int now;
void add(int x,int y){
    v[++now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
}
int pow(int a,int b){
    if(b==0){
        return 1;
    }
    if(b%2){
        return (pow(a,b-1)*a)%mod;
    }
    int temp=pow(a,b/2);
    return (temp*temp)%mod;
}
int fact[100005];
int inv[100005],w[100005];
int faa[100005];
void dfs(int now,int fa){
    faa[now]=fa;
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa){
            continue;
        }
        dfs(v[i],now);
    }
}
int C(int a,int b){
    return ((fact[a]*inv[b])%mod*inv[a-b])%mod;
}
int g[5005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("spacetime.in","r",stdin);
	freopen("spacetime.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=1;i<n;i++){
        int x=read();
        int y=read();
        add(x,y);
        add(y,x);
    }
    fact[0]=inv[0]=1;
    for(int i=1;i<=100000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=pow(fact[i],mod-2);
    }
    for(int i=1;i<=n;i++){
        w[i]=read();
    }
    for(int i=1;i<=std::min(n,5000ll);i++){
        int base=(fact[n-i]*C(n,i))%mod;
        for(int j=1;j<=i;j++){
            g[i]+=(((base*C(i,j))%mod*C(i-1,j-1))%mod*fact[i-j])%mod;
            g[i]%=mod;
        }
    }
    g[1]+=fact[n];
    g[1]%=mod;
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        int dep=0;
        for(int j=i;j!=0;j=faa[j]){
            dep++;
            ans+=(g[dep]*w[j])%mod;
            ans%=mod;
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


