#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int tree[32005];
int n=32002;
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
class node{
    public:
        int x,y;
        node(int a=0,int b=0){
            x=a;
            y=b;
            return ;
        }
}sq[15005];
int s[15005];
bool operator < (node a,node b){
    return a.x==b.x?a.y<b.y:a.x<b.x;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("stars.in","r",stdin);
	freopen("stars.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        sq[i].x=read()+1;
        sq[i].y=read()+1;
    }
    std::sort(sq+1,sq+1+n);
    for(int i=1;i<=n;i++){
        s[query(sq[i].y)]++;
        add(sq[i].y,1);
    }
    for(int i=0;i<n;i++){
        printf("%d\n",s[i]);
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


