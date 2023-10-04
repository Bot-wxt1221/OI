#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int n;
int tree[1000005];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int y){
    while(x<=n){
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
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("segment_tree.in","r",stdin);
	freopen("segment_tree.out","w",stdout);
	#endif
    n=read();
    int m=read();
    for(int i=1;i<=n;i++){
        add(i,read());
    }
    for(int i=1;i<=m;i++){
        int op=read();
        switch(op){
            case 1:{
                int l=read(),r;
                r=read();
                add(l,r);
                break;
            }
            case 2:{
                int t=read();
                int r=read();
                printf("%lld\n",query(r)-query(t-1));
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

