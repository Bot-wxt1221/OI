#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();
int a[100005];
#define SEQ_NODE long long
#define SEQ_ZERO 0
#define SEQ_SIZE 100000
class node{
	public:
		SEQ_NODE l,r,sum;
        bool yes=0;
		node(int a=0,int b=0,int c=0){
			l=a;
			r=b;
			sum=c;
			return ;
		}
};
class SEQ{
	public:
		node tree[SEQ_SIZE*8+5];
		SEQ_NODE lazy[SEQ_SIZE*8+5];
		SEQ(){
			return ;
		}
		SEQ_NODE merge(SEQ_NODE a,SEQ_NODE b){
			return a+b;
		}
		void build(int now,int l,int r){
			if(l>r){
				return ;
			}
			lazy[now]=SEQ_ZERO;
			if(l==r){
				tree[now].l=l;
				tree[now].r=r;
				tree[now].sum=a[l];
                tree[now].yes=(a[l]<=1);
				return ;
			}
			int mid=(l+r)/2;
			build(now*2,l,mid);
			build(now*2+1,mid+1,r);
			tree[now].l=l;
			tree[now].r=r;
			tree[now].sum=merge(tree[now*2].sum,tree[now*2+1].sum);
            tree[now].yes=tree[now*2].yes&&tree[now*2+1].yes;
			return ;
		}
		int ll,rr,tt;
		SEQ_NODE ques(int now,int l,int r){
			if(l>r){
				return SEQ_ZERO;
			}
			if(ll<=l&&r<=rr){
				return tree[now].sum;
			}
			if(r<ll||rr<l){
				return SEQ_ZERO;
			}
			int mid=(l+r)/2;
			return merge(ques(now*2,l,mid),ques(now*2+1,mid+1,r));
		}
		void mod(int now,int l,int r){
			if(l>r){
				return ;
			}
            if(tree[now].yes){
                return ;
            }
			if(ll<=l&&r<=rr&&l==r){
                tree[now].sum=std::sqrt(tree[now].sum);
				return ;
			}
			if(r<ll||rr<l){
				return ;
			}
			int mid=(l+r)/2;
			mod(now*2,l,mid);
			mod(now*2+1,mid+1,r);
			tree[now].sum=merge(tree[now*2].sum,tree[now*2+1].sum);
            tree[now].yes=tree[now*2].yes&&tree[now*2+1].yes;
			return ;
		}

}seq;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    seq.build(1,1,n);
    int m=read();
    for(int i=1;i<=m;i++){
        int op=read();
        seq.ll=read();
        seq.rr=read();
        switch(op){
            case 1:{
                printf("%lld\n",seq.ques(1,1,n));
                break;
            }
            case 2:{
                seq.mod(1,1,n);
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

