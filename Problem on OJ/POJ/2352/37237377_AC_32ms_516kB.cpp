#include <iostream>
#include <cstdio>
using namespace std;
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
int n=320000;
int tree[320005];
int lowbit(int a){
    return a&(-a);
}
void add(int a,int b){
    while(a<=n){
        tree[a]+=b;
        a+=lowbit(a);
    }
    return ;
}
int query(int a){
    int ans=0;
    while(a>0){
        ans+=tree[a];
        a-=lowbit(a);
    }
    return ans;
}
int ans[320005];
int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	int n=read();
    for(int i=1;i<=n;i++){
        int x=read();
        int y=read();
        x++;
        y++;
        ans[query(x)]++;
        add(x,1);
    }
    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }
	return 0;
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


