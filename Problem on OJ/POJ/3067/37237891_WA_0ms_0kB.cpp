#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
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
class node{
    public:
        int x,y;
}a[1000005];
int n=10005;
int tree[10005];
bool cmp(node a,node b){
    return (a.x==b.x)?(a.y<b.y):(a.x<b.x);
}
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
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	int T=read();
    int T2=T;
    while(T--){
        int n=read();
        int m=read();
        int k=read();
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=k;i++){
            a[i].x=read();
            a[i].y=read();
        }
        sort(a+1,a+k+1,cmp);
        int ans=0;
        for(int i=1;i<=k;i++){ 
            add(a[i].y,1);
            ans+=i-1-query(a[i].y);
        }
        printf("Test Case %lld: %lld\n",T2-T,ans);
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


