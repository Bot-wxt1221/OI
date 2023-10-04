#include <iostream>
#include <algorithm>
#include <cstdio>
inline int read();
class node{
    public:
        int x,y;
}a[1005];
bool cmp(node a,node b){
    return a.y>b.y;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n;
    int iii=0;
    while((n=read())!=0){
        for(int i=1;i<=n;i++){
            a[i].x=read();
            a[i].y=read();
        }
        std::sort(a+1,a+n+1,cmp);
        int time=0;
        int use=0;
        for(int i=1;i<=n;i++){
            time=std::max(time,a[i].x+a[i].y+use);
            use+=a[i].x;
        }
        printf("Case %d: %d\n",++iii,time);
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


