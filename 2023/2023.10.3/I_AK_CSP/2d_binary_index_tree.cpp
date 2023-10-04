#include <iostream>
#include <cstdio>
inline int read();
int lowbit(int a){
    return a&-a;
}
int tree[(1<<12)+5][(1<<12)+5],n,m;
int query(int x,int y){
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            ans+=tree[i][j];
        }
    }
    return ans;
}
int query2(int x1,int y1,int x2,int y2){
    return query(x1,y1)-query(x1,y2-1)-query(x2-1,y1)+query(x2-1,y2-1);
}
void add(int x,int y,int z){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            tree[i][j]+=z;
        }
    }
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("2d_binary_index_tree.in","r",stdin);
	freopen("2d_binary_index_tree.out","w",stdout);
	#endif
    n=read();
    m=read();
    int op;
    while(scanf("%d",&op)!=EOF){
        if(op==1){
            int x=read();
            int y=read();
            add(x,y,read());
        }else{
            int a=read();
            int b=read();
            int c=read();
            int d=read();
            printf("%d\n",query2(std::max(a,c),std::max(b,d),std::min(a,c),std::min(b,d)));
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


