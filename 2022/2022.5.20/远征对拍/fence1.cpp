#include <iostream>
#include <cstdio>
#include <queue>
#define int unsigned long long
using namespace std;
int read(){
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
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	int n=read(),total=0,ans=0;
	for(int i=1;i<=n;i++){
		a.push(-read());
	}
	for(int i=1;i<=n-1;i++){
		int a1=-a.top();
		a.pop();
		int a2=-a.top();
		a.pop();
		ans+=(a1+a2);
		a.push(-a1-a2);
	}
	cout<<ans;
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

