#include <cstdio>
//#define file

//********
#define SEQ_TYPE long long
int mod;
const int SEQ_SIZE=1000000+10;
struct node{
    SEQ_TYPE add,mul;
    SEQ_TYPE data;
    inline node(){
        add=0;
        mul=1;
        return;
    }
};

struct seq{
    node tree[SEQ_SIZE<<2];
    inline void build(int l,int r,int p,SEQ_TYPE *data){
        if(l==r){
            tree[p].data=data[l];
            return;
        }
        int mid=l+((r-l)>>1);
        build(l,mid,p<<1,data);
        build(mid+1,r,(p<<1)+1,data);
        tree[p].data=tree[p<<1].data+tree[(p<<1)+1].data;
        tree[p].data%=mod; 
        return;
    }

    inline SEQ_TYPE getsum(int l,int r,int s,int t,int p){
    	int mid=s+((t-s)>>1);
    	tree[p<<1].data=(tree[p].mul*tree[p<<1].data+tree[p].add*(mid-s+1))%mod;
        tree[(p<<1)+1].data=(tree[p].mul*tree[(p<<1)+1].data+tree[p].add*(t-mid))%mod;
        tree[p<<1].mul=(tree[p].mul*tree[p<<1].mul)%mod;
        tree[(p<<1)+1].mul=(tree[p].mul*tree[(p<<1)+1].mul)%mod;
        tree[p<<1].add=(tree[p].mul*tree[p<<1].add+tree[p].add)%mod;
        tree[(p<<1)+1].add=(tree[p].mul*tree[(p<<1)+1].add+tree[p].add)%mod;
        tree[p].add=0;
        tree[p].mul=1;
        if(l<=s&&t<=r) return tree[p].data%mod;
        
        SEQ_TYPE sum=0;
        if(l<=mid) sum=getsum(l,r,s,mid,p<<1);
        if(r>mid) sum=(sum+getsum(l,r,mid+1,t,(p<<1)+1))%mod;
        return sum;
    }

    inline void updatemul(int l,int r,int s,int t,int c,int p){
    	int mid=s+((t-s)>>1);
    	tree[p<<1].data=(tree[p].mul*tree[p<<1].data+tree[p].add*(mid-s+1))%mod;
        tree[(p<<1)+1].data=(tree[p].mul*tree[(p<<1)+1].data+tree[p].add*(t-mid))%mod;
        tree[p<<1].mul=(tree[p].mul*tree[p<<1].mul)%mod;
        tree[(p<<1)+1].mul=(tree[p].mul*tree[(p<<1)+1].mul)%mod;
        tree[p<<1].add=(tree[p].mul*tree[p<<1].add+tree[p].add)%mod;
        tree[(p<<1)+1].add=(tree[p].mul*tree[(p<<1)+1].add+tree[p].add)%mod;
        tree[p].add=0;
        tree[p].mul=1;
        if(l<=s&&t<=r){
            tree[p].data=(tree[p].data*c)%mod;
            tree[p].mul=(tree[p].mul*c)%mod;
            tree[p].add=(tree[p].add*c)%mod;
            return;
        }
        int sum=0;
        if(l<=mid) updatemul(l,r,s,mid,c,p<<1);
        if(r>mid) updatemul(l,r,mid+1,t,c,(p<<1)+1);
        tree[p].data=(tree[p<<1].data+tree[(p<<1)+1].data)%mod;
        return;
    }

    inline void updateadd(int l,int r,int s,int t,int c,int p){
    	int mid=s+((t-s)>>1);
    	tree[p<<1].data=(tree[p].mul*tree[p<<1].data+tree[p].add*(mid-s+1))%mod;
        tree[(p<<1)+1].data=(tree[p].mul*tree[(p<<1)+1].data+tree[p].add*(t-mid))%mod;
        tree[p<<1].mul=(tree[p].mul*tree[p<<1].mul)%mod;
        tree[(p<<1)+1].mul=(tree[p].mul*tree[(p<<1)+1].mul)%mod;
        tree[p<<1].add=(tree[p].mul*tree[p<<1].add+tree[p].add)%mod;
        tree[(p<<1)+1].add=(tree[p].mul*tree[(p<<1)+1].add+tree[p].add)%mod;
        tree[p].add=0;
        tree[p].mul=1;
        if(l<=s&&t<=r){
            tree[p].add=(tree[p].add+c)%mod;
            tree[p].data=(tree[p].data*tree[p].mul+tree[p].add*(t-s+1))%mod;
            return;
        }
        int sum=0;
        if(l<=mid) updateadd(l,r,s,mid,c,p<<1);
        if(r>mid) updateadd(l,r,mid+1,t,c,(p<<1)+1);
        tree[p].data=(tree[p<<1].data+tree[(p<<1)+1].data)%mod;
        return;
    }
}seq;
//********

inline long long read();
long long arr[SEQ_SIZE];

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    int n=read();
    int m=read();
    mod=read();

    for(register int i=1;i<=n;++i) arr[i]=read();

    seq.build(1,n,1,arr);

    char op;
    register int l,r,c;

    for(register int i=1;i<=m;++i){
        op=read();
        if(op==1){
            l=read();
            r=read();
            c=read();
            seq.updatemul(l,r,1,n,c,1);
        }else if(op==2){
            l=read();
            r=read();
            c=read();
            seq.updateadd(l,r,1,n,c,1);
        }else{
            l=read();
            r=read();
            printf("%lld\n",seq.getsum(l,r,1,n,1));
        }
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

inline long long read(){
    long long x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}