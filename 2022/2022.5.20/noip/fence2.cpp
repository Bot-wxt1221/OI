#include <iostream>
#include <cstdio>
#include <algorithm>
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
int a[20005];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	int n=read(),total=0,ans=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		total+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-1;i++){
		ans+=total;
		total-=a[i];
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

