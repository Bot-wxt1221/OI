#include <iostream>
#include <cstdio>
#define int long long
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
int h[80005];
int top=0;
int St[80005];
signed main(){
//	freopen("a.in","r",stdin);
//	freopen(".out","w",stdout);
	int n,ans=0;
	n=read();
	for(int i=1;i<=n;i++){
		h[i]=read();
		while(top>0&&St[top-1]<=h[i])	top--;
		ans+=top;
		St[top++]=h[i];
	}
	cout<<ans;
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