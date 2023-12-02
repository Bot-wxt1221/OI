#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int tree[4000005];
int lazy[4000005];
int lazy2[4000005];
int beg[4000005];
void init(int l,int r,int now){
    lazy[now]=-1000000005;
    int mid=(l+r)/2;
    if(l>r){
        return ;
    }
    if(l==r){
        tree[now]=beg[l];
        return ;
    }
    init(l,mid,now*2);
    init(mid+1,r,now*2+1);
    tree[now]=std::max(tree[now*2],tree[now*2+1]);
    return ;
}
void pushdown(int now){
    if(lazy[now]!=-1000000005){
        tree[now*2]=lazy[now]+lazy2[now];
        tree[now*2+1]=lazy[now]+lazy2[now];
        lazy[now*2]=lazy[now];
        lazy[now*2+1]=lazy[now];
        lazy[now]=-1000000005;
    }else{
        tree[now*2]+=lazy2[now];
        tree[now*2+1]+=lazy2[now];
    }
    lazy2[now*2]+=lazy2[now];
    lazy2[now*2+1]+=lazy2[now];
    return ;
}
int ll,rr,x;
void add1(int l,int r,int now){//1
    if(l>r){
        return ;
    }
    pushdown(now);
    if(ll<=l&&r<=rr){
        tree[now]=x;
        lazy[now]=x;
        return ;
    }
    if(ll>r||rr<l){
        return ;
    }
    int mid=(l+r)/2;
    add1(l,mid,now*2);
    add1(mid+1,r,now*2+1);
    tree[now]=std::max(tree[now*2],tree[now*2+1]);
    return ;
}
void add2(int l,int r,int now){//2
    if(l>r){
        return ;
    }
    pushdown(now);
    if(ll<=l&&r<=rr){
        tree[now]+=x;
        lazy2[now]+=x;
        return ;
    }
    if(ll>r||rr<l){
        return ;
    }
    int mid=(l+r)/2;
    add2(l,mid,now*2);
    add2(mid+1,r,now*2+1);
    tree[now]=std::max(tree[now*2],tree[now*2+1]);
    return ;
}
int que(int l,int r,int now){
    if(l>r){
        return -1000000005;
    }
    pushdown(now);
    if(ll<=l&&r<=rr){
        return tree[now];
    }
    if(ll>r||rr<l){
        return -1000000005;
    }
    int mid=(l+r)/2;
    return std::max(que(l,mid,now*2),que(mid+1,r,now*2+1));
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),q=read();
    for(int i=1;i<=n;i++){
        beg[i]=read();
    }
    init(1,n,1);
    for(int i=1;i<=q;i++){
        int op=read();
        switch(op){
            case 1:{
                ll=read();
                rr=read();
                x=read();
                add1(1,n,1);
                break ;
            }
            case 2:{
                ll=read();
                rr=read();
                x=read();
                add2(1,n,1);
                break;
            }
            case 3:{
                ll=read();
                rr=read();
                printf("%d\n",que(1,n,1));
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


