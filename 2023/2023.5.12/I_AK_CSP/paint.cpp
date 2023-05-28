#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 1000000009
inline int read();
class node{
    public:
        int y;
        char x;
}a[100005];
bool cmp(node a,node b){
    return a.y<b.y;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    for(int i=1;i<=m;i++){
        std::cin>>a[i].x;
        a[i].y=read();
    }
    int ans=1;
    std::sort(a+1,a+m+1,cmp);
    for(int i=1;i<m;i++){
        if(a[i].x==a[i+1].x){
            continue;
        }
        ans*=a[i+1].y-a[i].y;
        ans%=mod;
    }
    printf("%lld",ans);
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


