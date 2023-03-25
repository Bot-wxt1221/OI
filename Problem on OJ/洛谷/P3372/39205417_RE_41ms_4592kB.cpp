#include <iostream>
#include <cstdio>
#define ONLINE_JUDGE LUOGU
#define int long long
using namespace std;
inline int read();
int x,y,k;
int a[100005];
int b[400005];
int siz[400005];
int lazy[400005];
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
    return ;
}
inline void push_down(int now){
    b[now*2]+=lazy[now]*siz[now*2];
    b[now*2+1]+=lazy[now]*siz[now*2+1];
    lazy[now*2]+=lazy[now];
    lazy[now*2+1]+=lazy[now];
    lazy[now]=0;
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
        b[now]+=k*(min(r,y)-max(l,x)+1);
        lazy[now]+=k;
        return ;
    }else{
        int mid=(l+r)/2;
        add(l,mid,now*2);
        add(mid+1,r,now*2+1);
        b[now]=b[now*2]+b[now*2+1];
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
        return ;
    }else{
        int mid=(l+r)/2;
        ques(l,mid,now*2);
        ques(mid+1,r,now*2+1);
        b[now]=b[now*2]+b[now*2+1];
    }
    return ;
}
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    int m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    build(1,n,1);
    for(int i=1;i<=m;i++){
        int op=read();
        switch(op){
            case 1:{
                x=read();
                y=read();
                k=read();
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
