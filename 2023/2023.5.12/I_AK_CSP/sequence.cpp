#include <iostream>
#include <cstdio>
#define mod 1000000007
#define int long long
using namespace std;
inline int read();
int x,y,k,br;
int a[800005];
int b[800005];
int siz[800005];
int lazy1[800005];
int lazy2[800005];
void build(int l,int r,int now){
    if(l==r){
        b[now]=a[l];
        siz[now]=1;
        return ;
    }else if(l>r){
        return ;
    }
    siz[now]=(r-l+1);
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    b[now]=b[now*2]+b[now*2+1];
    b[now]%=mod;
    return ;
}
inline void push_down(int now){
    b[now*2]+=(lazy1[now]*siz[now*2])%mod;
    b[now*2]%=mod;
    b[now*2+1]+=(lazy1[now]*siz[now*2+1])%mod;
    b[now*2+1]%=mod;
    lazy1[now*2]+=lazy1[now];
    lazy1[now*2+1]+=lazy1[now];
    lazy1[now*2]%=mod;
    lazy1[now*2+1]%=mod;
    
    int last=((siz[now*2]-1)*lazy2[now])%mod;
    b[now*2]+=((((last)*siz[now*2])%mod)*500000004)%mod;
    b[now*2]%=mod;
    int last2=((siz[now]-1)*lazy2[now])%mod;
    b[now*2+1]+=((((last+lazy2[now]+last2)*(siz[now*2+1]))%mod)*500000004)%mod;
    b[now*2+1]%=mod;
    lazy2[now*2]+=lazy2[now];
    lazy2[now*2+1]+=lazy2[now];
    lazy1[now*2+1]+=(last+lazy2[now])%mod;
    lazy1[now]=0;
    lazy2[now]=0;
    lazy1[now*2]%=mod;
    lazy1[now*2+1]%=mod;
    lazy2[now*2]%=mod;
    lazy2[now*2+1]%=mod;
    return ;
}
void add(int l,int r,int now){
    
    if(l>r){
        return ;
    }
    push_down(now);
    if(r<x||y<l){
        return ;
    }
    if(x<=l&&r<=y){
        b[now]+=(br*(r-l+1))%mod;
        b[now]%=mod;
        int first=((l-x)*k)%mod;
        int last=((r-x)*k)%mod;
        b[now]+=((((((first+last)%mod)*(r-l+1)%mod))%mod)*500000004)%mod;
        lazy1[now]+=(br+first)%mod;
        lazy2[now]+=k;
        return ;
    }else{
        int mid=(l+r)/2;
        add(l,mid,now*2);
        add(mid+1,r,now*2+1);
        b[now]=(b[now*2]+b[now*2+1])%mod;
    }
    return ;
}
void ques(int l,int r,int now){
    
    if(l>r){
        return ;
    }
    push_down(now);
    if(r<x||y<l){
        return ;
    }
    if(x<=l&&r<=y){
        k+=b[now];
        k%=mod;
        return ;
    }else{
        int mid=(l+r)/2;
        ques(l,mid,now*2);
        ques(mid+1,r,now*2+1);
    }
    return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	#endif
    int n=read();
    int m=read();
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
    build(1,n,1);
    for(int i=1;i<=m;i++){
        int op=read();
        switch(op){
            case 1:{
                x=read();
                y=read();
                k=read();
                br=read();
                add(1,n,1);
                break;
            }
            case 2:{
                x=read();
                y=read();
                k=0;
                ques(1,n,1);
                printf("%lld\n",k);
                break;
            }
        }
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