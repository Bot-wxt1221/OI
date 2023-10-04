#include <iostream>
#include <cstdio>
inline int read();
int n;
int tree[100005];
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
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	#endif
    n=read();
    int m=read();
    for(int i=1;i<=m;i++){
        int op=read();
        switch(op){
            case 1:{
                int l=read(),r;
                r=read();
                add(r+1,-1);
                add(l,1);
                break;
            }
            case 2:{
                int t=read();
                printf("%d\n",query(t)%2);
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

