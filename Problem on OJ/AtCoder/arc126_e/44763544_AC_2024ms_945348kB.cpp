#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int seq[3000005];
class node{
    public:
        int num,siz;
        int l,r;
        node(){
            l=r=2;
        }
}tree[30000005];
int head=1;
int nowto=2;
int tno,xx;
int insert(int now,int l,int r){
    if(now==2){
        now=++nowto;
    }
    if(l==r){
        tree[now].num+=(l)*xx;
        tree[now].siz+=1*xx;
        return now;
    }
    int mid=(l+r)/2;
    if(tno<=mid){
        tree[now].l=insert(tree[now].l,l,mid);
    }else{
        tree[now].r=insert(tree[now].r,mid+1,r);
    }
    tree[now].num=(tree[tree[now].l].num+tree[tree[now].r].num)%mod;
    tree[now].siz=(tree[tree[now].l].siz+tree[tree[now].r].siz)%mod;
    return now;
}
int ll,rr,siz;
int getans(int now,int l,int r){
    if(now==2){
        return 0;
    }
    if(r<ll||rr<l){
        return 0;
    }
    if(ll<=l&&r<=rr){
        siz+=tree[now].siz;
        return tree[now].num;
    }
    int mid=(l+r)/2;
    return (getans(tree[now].l,l,mid)+getans(tree[now].r,mid+1,r))%mod;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("03_rand_01.txt","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    int q=read();
    for(int i=1;i<=n;i++){
        seq[i]=read();
        tno=seq[i];
        xx=1;
        insert(1,1,1000000000);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ll=seq[i]+1,rr=1000000000;
        siz=0;
        ans+=getans(1,1,1000000000)-siz*seq[i];
        ans%=mod;
    }
    for(int i=1;i<=q;i++){
        int x=read();
        int to=read();
        ll=seq[x]+1,rr=1000000000;
        siz=0;
        ans-=getans(1,1,1000000000)-siz*seq[x];
        ans%=mod;
        ll=1,rr=seq[x]-1;
        siz=0;
        int temp=getans(1,1,1000000000);
        ans-=siz*seq[x]-temp;
        ans%=mod;
        tno=seq[x];
        xx=-1;
        insert(1,1,1000000000);
        seq[x]=to;
        tno=seq[x];
        xx=1;
        insert(1,1,1000000000);
        ll=seq[x]+1,rr=1000000000;
        siz=0;
        ans+=getans(1,1,1000000000)-siz*seq[x];
        ans%=mod;
        ll=1,rr=seq[x]-1;
        siz=0;
        temp=getans(1,1,1000000000);
        ans+=siz*seq[x]-temp;
        ans%=mod;
        printf("%lld\n",(((((long long)(ans))*499122177)%mod)+mod)%mod);
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


