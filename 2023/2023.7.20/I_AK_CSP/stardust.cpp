#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
inline int lowbit(int x){
    return x&-x;
}
class BIT{
    public:
        int tree[500005];
        void add(int x,int y){
            while(x<=500002){
                tree[x]+=y;
                x+=lowbit(x);
            }
            return ;
        }
        int query(int x){
            int ans=0;
            while(x>0){
                ans+=tree[x];
                x-=lowbit(x);
            }
            return ans;
        }
}t1,t2;
int ans;
int fir[500005];
int nxt[1000005];
int v[1000005];
int now;
void add(int x,int y){
    now++;
    v[now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
}
int w[500005];
int delta[500005];
int dep[500005];
void dfs(int now,int fa){
    dep[now]=dep[fa]+1;
    ans+=dep[now];
    ans-=t1.query(w[now]);
    delta[now]+=t1.query(w[now]);
    int tt=t2.query(500002)-t2.query(w[now]);
    t1.add(w[now],1);
    t2.add(w[now],1);
    for(int i=fir[now];i!=-1;i=nxt[i]){
        if(v[i]==fa){
            continue;
        }
        dfs(v[i],now);
    }
    delta[now]+=t2.query(500002)-t2.query(w[now])-tt;
    t1.add(w[now],-1);
    delta[now]-=dep[now];
    return ;
}
void print(int x){
    if(x==0){
        putchar('0');
        return ;
    }
    char temp[35];
    int now=0;
    while(x>0){
        temp[++now]=x%10;
        x/=10;
    }
    for(int i=now;i>=1;i--){
        putchar(temp[i]+'0');
    }
    return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("stardust.in","r",stdin);
	freopen("stardust.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        w[i]=read()+1;
        fir[i]=-1;
    }
    for(int i=1;i<n;i++){
        int u=read(),v;
        v=read();
        add(u,v);
        add(v,u);
    }
    ans=(n)*(n-1)/2;
    dep[1]=-1;
    dfs(1,1);
    print(ans);
    putchar(' ');
    std::sort(delta+1,delta+n+1);
    for(int i=1;i<=n;i++){
        ans-=(n-i);
        ans+=delta[i];
        print(ans);
        putchar(' ');
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


