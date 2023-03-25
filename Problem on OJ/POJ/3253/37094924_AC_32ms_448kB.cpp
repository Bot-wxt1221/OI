#include <iostream>
#include <cstdio>
#include <queue>
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
priority_queue<int>a;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a.push(-read());
	}
	int ans=0;
	while(a.size()>1){
		int c=-a.top();
		a.pop();
		int b=-a.top();
		a.pop();
		ans+=c;
		ans+=b;
		a.push(-b-c);
	}
	printf("%lld",ans);
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


