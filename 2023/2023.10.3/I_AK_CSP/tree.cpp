#include <iostream>
#include <cstdio>
inline int read();
int n;
class BIT{
    public:
        int tree[50005];
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
}b1,b2;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	#endif
    n=50001;
    read();
    int ans=0;
    int m=read();
    for(int i=1;i<=m;i++){
        int k=read();
        switch(k){
            case 1:{
                int l=read(),r;
                r=read();
                b1.add(r,1);
                b2.add(50001-l,1);
                ans++;
                break;
            }
            case 2:{
                int l=read();
                int r=read();
                printf("%d\n",ans-b1.query(l-1)-b2.query(50000-r));
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

