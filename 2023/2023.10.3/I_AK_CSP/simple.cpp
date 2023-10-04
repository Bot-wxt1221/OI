#include <iostream>
#include <cstdio>
inline int read();
#define SEQ_NODE long long
#define SEQ_ZERO 0
#define SEQ_SIZE 1000000
class node{
	public:
		SEQ_NODE l,r,sum;
		node(int a=0,int b=0,int c=0){
			l=a;
			r=b;
			sum=c;
			return ;
		}
};
class SEQ{
	public:
		node tree[SEQ_SIZE*4+5];
		SEQ_NODE lazy[SEQ_SIZE*4+5];
		SEQ(){
			return ;
		}
		SEQ_NODE merge(SEQ_NODE a,SEQ_NODE b){
			return a+b;
		}
		void lazyadd(int now,int tt){
			tree[now].sum=merge(tree[now].sum,tt*(tree[now].r-tree[now].l+1));
			return ;
		}
		void pushdown(int now){
			lazyadd(now*2,lazy[now]);
			lazy[now*2]=merge(lazy[now*2],lazy[now]);
			lazyadd(now*2+1,lazy[now]);
			lazy[now*2+1]=merge(lazy[now*2+1],lazy[now]);
			lazy[now]=SEQ_ZERO;
			return ;
		}
    int debug=0;
		void build(int now,int l,int r){
			if(l>r){
				return ;
			}
      debug=std::max(debug,now);
			lazy[now]=SEQ_ZERO;
			if(l==r){
				tree[now].l=l;
				tree[now].r=r;
				tree[now].sum=SEQ_ZERO;
				return ;
			}
			int mid=(l+r)/2;
			build(now*2,l,mid);
			build(now*2+1,mid+1,r);
			tree[now].l=l;
			tree[now].r=r;
			tree[now].sum=merge(tree[now*2].sum,tree[now*2+1].sum);
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
      pushdown(now);
			int mid=(l+r)/2;
			return merge(ques(now*2,l,mid),ques(now*2+1,mid+1,r));
		}
		void mod(int now,int l,int r){
			if(l>r){
				return ;
			}	
			if(ll<=l&&r<=rr){
				lazy[now]=merge(lazy[now],tt);
				lazyadd(now,tt);
				return ;
      }
			if(r<ll||rr<l){
				return ;
			}
      pushdown(now);
			int mid=(l+r)/2;
			mod(now*2,l,mid);
			mod(now*2+1,mid+1,r);
			tree[now].sum=merge(tree[now*2].sum,tree[now*2+1].sum);
			return ;
		}

}seq;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("simple.in","r",stdin);
	freopen("simple.out","w",stdout);
	#endif
    int n=read(),m;
	m=read();
	seq.build(1,1,n);
	for(int i=1;i<=n;i++){
		seq.ll=i;
		seq.rr=i;
		seq.tt=read();
		seq.mod(1,1,n);
	}
	for(int i=1;i<=m;i++){
		int op=read();
		seq.ll=read();
		seq.rr=read();
		switch(op){
			case 1:{//mod
				seq.tt=read();
				seq.mod(1,1,n);
				break;
			}
			case 2:{//que
				printf("%lld\n",seq.ques(1,1,n));
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


