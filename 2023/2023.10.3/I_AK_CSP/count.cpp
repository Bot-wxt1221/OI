#include <iostream>
#include <cstdio>
inline int read();

char temp[5];
int tree[500005];
int n;
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
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	#endif
    n=read();
    int k=read();
    for(int i=1;i<=k;i++){
        scanf("%s",temp+1);
        if(temp[1]=='A'){
            int m=read();
            printf("%d\n",query(m));
        }else if(temp[1]=='B'){
            int m=read();
            add(m,read());
        }else{
            int m=read();
            add(m,-read());
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


