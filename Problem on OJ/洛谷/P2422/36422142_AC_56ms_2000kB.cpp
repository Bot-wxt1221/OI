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
int a[100005];
int qian[100005];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		qian[i]=qian[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=i; 
		while(l>=1&&a[i]<=a[l])	l--;
		while(r<=n&&a[i]<=a[r])	r++;
		l++;
		r--;
		ans=max(ans,(qian[r]-qian[l-1])*a[i]);
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
