#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
#define mod 998244353
inline int read();
int p[400005];
int q[200005];
int pos[200005];
int lowbit(int x){
    return (x)&(-x);
}
class BIT{
    public:
        int tree[600005];
        int query(int x){
            int ans=0;
            while(x>0){
                ans+=tree[x];
                ans%=mod;
                x-=lowbit(x);
            }
            return ans;
        }
        void add(int x,int y){
            while(x<=600000){
                tree[x]+=y;
                tree[x]%=mod;
                x+=lowbit(x);
            }
            return ;
        }
}a,b;
int pow(int x,int y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        int temp=pow(x,y/2);
        return (temp*temp)%mod;
    }
    return (pow(x,y-1)*x)%mod;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int t=read();
    while(t--){
        int n=read();
        int k=read();
        for(int i=1;i<=n;i++){
            p[i]=read();
        }
        int yy=0;
        for(int i=1;i<=k;i++){
            q[i]=read();
            q[i]++;
            pos[q[i]]=i;
            a.add(q[i],1);
            yy+=(i-a.query(q[i]))%mod+mod;
            yy%=mod;
        }
        int bb=std::min(k,25ll);
        int anscnt=yy*n;
        anscnt%=mod;
        for(int i=1;i<=n;i++){
            anscnt+=((((k-bb-1)*(k-bb)/2)%mod)*i)%mod;
            anscnt%=mod;
            for(int j=0;j<=bb;j++){
                int req=std::min(pow(2,j)*p[i],600000ll);
                if (req % 2 == 0) req += 1;
                anscnt+=((k-j)%mod*(((i-1-b.query(req-1))%mod)+mod)%mod)%mod;
                anscnt%=mod;
            }
            for(int j=1;j<=bb;j++){
                int req=std::min(p[i]/pow(2,j)+1,600000ll);
                if (req % 2 == 0) req += 1;
                anscnt+=((k-j)%mod*(((i-1-b.query(req-1))%mod)+mod)%mod)%mod;
                anscnt%=mod;
            }
            b.add(p[i],1);
        }
        for(int i=1;i<=k;i++){
            a.add(q[i],-1);
        }
        for(int i=1;i<=n;i++){
            b.add(p[i],-1);
        }
        printf("%lld\n",anscnt);
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