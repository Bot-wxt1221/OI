#include <iostream>
#include <cstdio>
#include <queue>
#define int unsigned long long
inline int read();
std::priority_queue<int>a;
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        a.push(-read());
    }
    int ans=0;
    while(a.size()>1){
        int temp=-a.top();
        a.pop();
        int temp2=-a.top();
        a.pop();
        ans+=temp+temp2;
        a.push(-temp-temp2);
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


